class Solution {
    int f(int n,vector<int> &dp){
        if(n<=0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int mincount=INT_MAX;

        for(int i=1;i*i<=n;i++){
            int res=1+f(n-i*i,dp);
            mincount=min(mincount,res);
        }
        return  dp[n]=mincount;
    }
public:
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};