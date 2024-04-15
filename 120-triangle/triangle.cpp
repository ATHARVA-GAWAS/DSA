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
        vector<int> after(n+1,0),cur(n+1,0);
        for(int j=0;j<n;j++){
            after[j] = triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                if(i==n-1){
                    cur[j]= triangle[n-1][j];
                }
                int d=triangle[i][j]+after[j];
                int dg=triangle[i][j]+after[j+1];
                cur[j]=min(d,dg);
            }
            after=cur;
        }
       return after[0];
    }
};