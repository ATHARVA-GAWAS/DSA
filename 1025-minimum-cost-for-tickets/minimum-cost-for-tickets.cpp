class Solution {
public:
    
    int func(int i, int upto, vector<int>& days, vector<int>& costs, vector<vector<int>>& dp) {
        if (i == days.size()) return 0;

        if (days[i] <= upto) return func(i + 1, upto, days, costs, dp);

        if (dp[i][upto] != -1) return dp[i][upto];

        int a = costs[0] + func(i + 1, days[i], days, costs, dp);
        int b = costs[1] + func(i + 1, days[i] + 6, days, costs, dp);
        int c = costs[2] + func(i + 1, days[i] + 29, days, costs, dp);

        return dp[i][upto] = min(a, min(b, c));
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> dp(days.size(), vector<int>(366, -1));
        return func(0, 0, days, costs, dp);
    }
};
