class Solution {
public:
int solve(int ind,vector<int> &dp){
    if(ind==1){
        return 1;
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }
    int res=1*(ind-1);
    for(int i=1;i<=ind-1;i++){
        int prod=i*max(ind-i,solve(ind-i,dp));
        res=max(res,prod);
    }
    return dp[ind]=res;
}
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};