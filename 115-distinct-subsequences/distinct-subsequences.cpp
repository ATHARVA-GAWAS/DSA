class Solution {

    int solve(string &s, string &t, int len1, int len2, vector<vector<int>> &dp) {

        if(len2 < 0) return 1;

        if(len1 < 0) return 0;

        if(dp[len1][len2] != -1) {
            return dp[len1][len2];
        }

        int take = 0;
        int ntake = 0;

        if(s[len1] == t[len2]) {
            take = solve(s, t, len1 - 1, len2 - 1, dp);
        }

        ntake = solve(s, t, len1 - 1, len2, dp);

        return dp[len1][len2] = take + ntake;
    }
public:
    int numDistinct(string s, string t) {
        
        int len1 = s.length();
        int len2 = t.length();

        vector<vector<int>> dp(len1 + 1, vector<int>(len2+1,-1));

        return solve(s,t,len1-1,len2-1,dp);
    }
};