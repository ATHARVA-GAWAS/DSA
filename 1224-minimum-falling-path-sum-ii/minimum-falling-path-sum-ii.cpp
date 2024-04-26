class Solution {
    int f(vector<vector<int>>& grid,int i,int j,vector<vector<int>> &dp){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0||j>=m||j<0)return 1e9;
        if(i==0){
            return grid[i][j];
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int temp=INT_MAX;
        for(int k=0;k<n;k++){
            if(k==j){
               continue;
            }
            temp=min(temp,grid[i][j]+ f(grid, i - 1, k,dp));
        }
        return dp[i][j]=temp;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=INT_MAX;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<m;i++){
            int cur=f(grid,n-1,i,dp);
            ans=min(ans,cur);
        }
        return ans;
    }
};