class Solution {
    int f(int i,int j, vector<vector<int>>&matrix,vector<vector<int>> &dp){
        if(i<0 || j<0 || matrix[i][j]==0){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int a=f(i-1,j,matrix,dp);
        int b=f(i-1,j-1,matrix,dp);
        int c=f(i,j-1,matrix,dp);

        return dp[i][j]=1+min(a,min(b,c));
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        int cnt=0;

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cnt=cnt+f(i,j,matrix,dp);
            }
        }

        return cnt;
    }
};