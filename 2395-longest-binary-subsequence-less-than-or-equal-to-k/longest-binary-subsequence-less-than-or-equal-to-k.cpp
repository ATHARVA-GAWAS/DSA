class Solution {
public:
    int f(int ind, int size, int sum, string &s, vector<vector<int>>& dp) {
        if (ind<0){
            return 0;
        } 
        if (dp[ind][size] != -1){
            return dp[ind][size];
        } 

        int nottake = f(ind-1,size,sum,s,dp);
        int take = 0;

        if ((sum-(s[ind]-'0')*pow(2,size))>=0) {
            take = 1+f(ind-1,size+1,sum-(s[ind]-'0')*pow(2,size),s,dp);
        }

        return dp[ind][size] = max(nottake, take);
    }

    int longestSubsequence(string s, int k) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n,-1));

        return f(n-1,0,k,s,dp);
    }
};