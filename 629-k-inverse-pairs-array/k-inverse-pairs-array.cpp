class Solution {
    int mod=1e9+7;
    int f(int n,int k,vector<vector<int>> &dp){
        if(n==0){
            return 0;
        }
        if(k==0){
            return 1;
        }
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        int cnt=0;
        for(int i=0;i<=min(n-1,k);i++){
            cnt=(cnt+f(n-1,k-i,dp)%mod)%mod;
        }
        return dp[n][k]=cnt%mod;
    }
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return f(n,k,dp);
    }
};