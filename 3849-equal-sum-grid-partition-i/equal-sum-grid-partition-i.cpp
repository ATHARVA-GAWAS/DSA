class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<long long> rowsum(n,0),colsum(m,0);

        long long totsum=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                totsum+=grid[i][j];

                rowsum[i]+=grid[i][j];
                colsum[j]+=grid[i][j];
            }
        }

        if(totsum%2!=0){
            return false;
        }

        long long upper=0;

        for(int i=0;i<n-1;i++){
            upper+=rowsum[i];

            if(upper==totsum-upper){
                return true;
            }
        }

        long long left=0;

        for(int j=0;j<m-1;j++){
            left+=colsum[j];

            if(left==totsum-left){
                return true;
            }
        }

        return false;
    }
};