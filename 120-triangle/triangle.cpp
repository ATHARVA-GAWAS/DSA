class Solution {
    int f(int i, int j,vector<vector<int>>& triangle, int n,vector<vector<int>> &dp){
        if(i==n-1){
            return triangle[n-1][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int d=triangle[i][j]+f(i+1,j,triangle,n,dp);
        int dg=triangle[i][j]+f(i+1,j+1,triangle,n,dp);
        return dp[i][j]=min(d,dg);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[0].size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(0,0,triangle,n,dp);
    }
};