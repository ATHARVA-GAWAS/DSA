class Solution {
    int f(int i,int j,vector<vector<int>>&nums,vector<vector<int>> &dp){
        int n=nums.size();
        int m=nums[0].size();

        if(i<0 || j<0){
            return 1e9;
        }

        if(i==0 && j==0){
            return nums[i][j];
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int left=nums[i][j]+f(i,j-1,nums,dp);
        int up=nums[i][j]+f(i-1,j,nums,dp);

        return dp[i][j]=min(left,up);        
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        return f(n-1,m-1,grid,dp);
    }
};