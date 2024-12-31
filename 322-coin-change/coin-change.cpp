class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX));
        
        for (int amt = 0; amt <= amount; ++amt) {
            if (amt % coins[0] == 0) {
                dp[0][amt] = amt / coins[0];
            }
        }

        for (int ind = 1; ind < n; ind++) {
            for (int amt = 0; amt <= amount; amt++) {
                int notpick = dp[ind - 1][amt];

                int pick = INT_MAX;

                if (coins[ind] <= amt) { 
                    int sub_res = dp[ind][amt - coins[ind]];
                    if (sub_res != INT_MAX) { // Prevent overflow
                        pick = 1 + sub_res;
                    }
                }

                dp[ind][amt] = min(pick, notpick);
            }
        }

        return dp[n - 1][amount] == INT_MAX ? -1 : dp[n - 1][amount];
    }
};