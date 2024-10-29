class Solution {
    int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &dp){
        
        if(j==grid[0].size()-1){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int cur=grid[i][j];

        int a=0,b=0,c=0;

        if(i-1>=0 && j+1<grid[0].size() && grid[i-1][j+1]>cur){
            a=1+f(i-1,j+1,grid,dp);
        }
        if( j+1<grid[0].size() && grid[i][j+1]>cur){
            b=1+f(i,j+1,grid,dp);
        }
        if(i+1<grid.size() && j+1<grid[0].size() && grid[i+1][j+1]>cur){
            c=1+f(i+1,j+1,grid,dp);
        }

        return dp[i][j]=max(a,max(b,c));
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        int ans=0;

        for(int i=0;i<n;i++){
            ans=max(ans,f(i,0,grid,dp));
        }
        return ans;
    }
};