class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1, 0);
        for(int i=n-2; i>=0; i--){
            dp[i]=min(cost[i]+dp[i+1], cost[i+1]+dp[i+2]);
        }
        return dp[0];
    }
};