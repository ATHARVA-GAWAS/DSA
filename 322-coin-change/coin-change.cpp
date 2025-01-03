class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

        vector<int> prev(amount + 1, INT_MAX),cur(amount + 1, INT_MAX);
        
        for (int amt = 0; amt <= amount; ++amt) {
            if (amt % coins[0] == 0) {
                prev[amt] = amt / coins[0];
            }
        }

        for (int ind = 1; ind < n; ind++) {
            for (int amt = 0; amt <= amount; amt++) {
                int notpick = prev[amt];

                int pick = INT_MAX;

                if (coins[ind] <= amt) { 
                    int sub_res = cur[amt - coins[ind]];
                    if (sub_res != INT_MAX) { // Prevent overflow
                        pick = 1 + sub_res;
                    }
                }

                cur[amt] = min(pick, notpick);
            }
            prev=cur;
        }

        return prev[amount] == INT_MAX ? -1 :prev[amount];
    }
};