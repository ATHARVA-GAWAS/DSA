class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        int ans=0;

        vector<vector<int>> prefsum(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                prefsum[i][j]=grid[i][j];

                if(i>0){
                    prefsum[i][j]+=prefsum[i-1][j];
                }

                if(j>0){
                    prefsum[i][j]+=prefsum[i][j-1];
                }

                if(i>0 && j>0){
                    prefsum[i][j]-=prefsum[i-1][j-1];
                }

                if(prefsum[i][j]<=k){
                    ans++;
                }
            }
        }

        return ans;
    }
};