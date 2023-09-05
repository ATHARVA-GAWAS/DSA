class Solution {
    int f(int ind1,int ind2,string s,string s2,vector<vector<int>> dp){
        if(ind1<0 || ind2<0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        if(s[ind1]==s2[ind2]){
            return dp[ind1][ind2]= 1+f(ind1-1,ind2-1,s,s2,dp);
        }
        return dp[ind1][ind2]=max(f(ind1-1,ind2,s,s2,dp),f(ind1,ind2-1,s,s2,dp));
    }
public:
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s.begin(),s.end());
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int j=0;j<=n;j++){
            dp[0][j]=0;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                 if(s[ind1-1]==s2[ind2-1]){
                  dp[ind1][ind2]= 1+dp[ind1-1][ind2-1];
               }
               else{
                    dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
               }
              
            }
        }
        return dp[n][n];

    }
};