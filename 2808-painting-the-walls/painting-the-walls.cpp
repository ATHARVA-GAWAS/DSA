class Solution {
    int f(int ind,int remaining_wall,vector<int>& cost,vector<int>& time,vector<vector<int>> &dp){
        if(remaining_wall<=0){
            return 0;
        }
        if(ind>=cost.size()){
            return 1e9;
        }
        if(dp[ind][remaining_wall]!=-1){
            return dp[ind][remaining_wall];
        }
        int paint=cost[ind]+f(ind+1,remaining_wall-1-time[ind],cost,time,dp);
        int notpaint=0+f(ind+1,remaining_wall,cost,time,dp);
        return dp[ind][remaining_wall]=min(paint,notpaint);
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
       
        int n=cost.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(0,n,cost,time,dp);
    }
};