class Solution {
    int f(int ind1,int ind2,string text1, string text2,vector<vector<int>> &dp){
        if(ind1<0 || ind2<0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        int take=0,nottake1=0,nottake2=0;
        if(text1[ind1]==text2[ind2]){
            take=1+f(ind1-1,ind2-1,text1,text2,dp);
        }
        else{
            nottake1=0+f(ind1-1,ind2,text1,text2,dp);
            nottake2=0+f(ind1,ind2-1,text1,text2,dp);
        }
        return dp[ind1][ind2]=max(take,max(nottake1,nottake2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                   dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }
};