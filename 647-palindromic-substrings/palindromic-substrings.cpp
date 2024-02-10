class Solution {
    bool isPalindrome(int i,int j, string str,vector<vector<int>> &dp){
        if(i >= j) {
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(str[i] == str[j]) {
            return dp[i][j]=isPalindrome(i+1, j-1,str,dp);
        }

        return dp[i][j]=false;
    }
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s,dp)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};