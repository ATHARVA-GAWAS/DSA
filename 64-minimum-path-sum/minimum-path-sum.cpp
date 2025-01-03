class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<int> prev(n+1,0),cur(m+1,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    cur[j]=grid[i][j];
                }

                else{
                    int up = grid[i][j];

                    if(i>0){
                        up += prev[j];
                    } 
                    else{
                        up += 1e9;
                    } 
                
                    int left = grid[i][j];
                    if(j>0){
                        left+=cur[j-1];
                    } 
                    else{
                        left += 1e9;
                    } 

                    cur[j]=min(left,up);
                }

            }
            prev=cur;
        }
        
        return prev[m-1];
    }
};