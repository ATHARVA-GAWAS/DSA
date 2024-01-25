class Solution {
    int f(int ind1,int ind2,string &text1, string &text2,vector<vector<int>> &dp){
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
        nottake1=0+f(ind1-1,ind2,text1,text2,dp);
        nottake2=0+f(ind1,ind2-1,text1,text2,dp);
        return dp[ind1][ind2]=max(take,max(nottake1,nottake2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return f(n1-1,n2-1,text1,text2,dp);
    }
};