class Solution {
    int lcsAscii(int i, int j, string &s1, string &s2,vector<vector<int>> &dp) {
        if (i == s1.length() || j == s2.length()){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
            

        if (s1[i] == s2[j]) {
            return dp[i][j]=s1[i]+lcsAscii(i+1,j+1,s1,s2,dp);
        } 
        else {
            return dp[i][j]=max(
                lcsAscii(i+1,j,s1,s2,dp),
                lcsAscii(i,j+1,s1,s2,dp)
            );
        }
    }

public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();

        int total = 0;

        for (char c : s1){
            total += c;
        } 
        for (char c : s2){
            total += c;
        } 

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        int common = lcsAscii(0, 0, s1, s2,dp);

        return total-2*common;
    }
};
