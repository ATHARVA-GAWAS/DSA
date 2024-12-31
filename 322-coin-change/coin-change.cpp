class Solution {
    int f(int ind,int amount,vector<int>&coins,vector<vector<int>> &dp){
        if(ind<0){
            return 0;
        }

        if(ind==0){
            if(amount%coins[ind]==0){
                return amount/coins[ind];
            }
            else{
                return INT_MAX;
            }
        }

        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }

        int notpick=0+f(ind-1,amount,coins,dp);

        int pick=INT_MAX;

        if(coins[ind]<=amount){
            int sub_res = f(ind, amount - coins[ind], coins,dp);
            if (sub_res != INT_MAX) {  // Prevent overflow
                pick = 1 + sub_res;
            }
        }

        return dp[ind][amount]=min(pick,notpick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));

        int ans=f(n-1,amount,coins,dp);

        if(ans>=INT_MAX){
            return -1;
        }

        return ans;
    }
};