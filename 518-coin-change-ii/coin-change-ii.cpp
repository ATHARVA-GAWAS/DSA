class Solution {
    int f(int ind,int amount,vector<int>&coins,vector<vector<int>> &dp){
        if(ind==0){
            return (amount%coins[ind]==0);
        }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }

        int notpick=f(ind-1,amount,coins,dp);
        int pick=0;
        if(coins[ind]<=amount){
            pick=f(ind,amount-coins[ind],coins,dp);
        }

        return dp[ind][amount]=pick+notpick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
};