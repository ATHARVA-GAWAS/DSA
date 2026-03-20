class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> res(n-k+1, vector<int>(m-k+1, 0));

        for(int i=0;i<=n-k;i++){
            for(int j=0;j<=m-k;j++){

                set<int> vals;

                for(int r=i;r<=i+k-1;r++){
                    for(int c=j;c<=j+k-1;c++){
                        vals.insert(grid[r][c]);
                    }
                }


                if(vals.size()==1){ // If all elements were same, set has only 1 element
                    continue;
                }

                int minabsdiff=INT_MAX;

                auto prev=vals.begin();
                auto curr=next(prev);

                while(curr!=vals.end()){
                    minabsdiff=min(minabsdiff,*curr - *prev);
                    prev=curr;
                    curr++;
                }

                res[i][j]=minabsdiff;
            }
        }

        return res;
    }
};