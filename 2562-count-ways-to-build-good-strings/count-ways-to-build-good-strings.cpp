class Solution {
public:
    const int mod = 1e9+7;

    int f(int low,int high,int zero,int one,int len,vector<int> &dp){
        if(len > high){
            return 0;
        } 

        if(dp[len]!=-1){
            return dp[len];
        }
        
        int ans = (len >= low) ? 1 : 0;

        ans = (ans + f(low,high,zero,one,len+zero,dp)) % mod;
        ans = (ans + f(low,high,zero,one,len+one,dp)) % mod;

        return dp[len]=ans;
    }

    int countGoodStrings(int low, int high, int zero, int one) {

        vector<int> dp(high+1,-1);
        return f(low,high,zero,one,0,dp);
    }
};