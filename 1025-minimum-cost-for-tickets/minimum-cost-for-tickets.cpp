class Solution {
public:
    int f(int ind,int upto,vector<int>& days, vector<int>& costs,vector<vector<int>> &dp){
        if(ind==days.size()){
            return 0;
        }

        

        if(days[ind]<=upto){
            return f(ind+1,upto,days,costs,dp);
        }

        if(dp[ind][upto]!=-1){
            return dp[ind][upto];
        }
        
        int a=costs[0]+f(ind+1,days[ind],days,costs,dp);
        int b=costs[1]+f(ind+1,days[ind]+6,days,costs,dp);
        int c=costs[2]+f(ind+1,days[ind]+29,days,costs,dp);

        return dp[ind][upto]=min(a,min(b,c));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();

        vector<vector<int>> dp(n+1,vector<int>(366,-1));

        return f(0, 0, days, costs,dp);
    }
};
