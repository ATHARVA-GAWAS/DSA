class Solution {
    int f(int ind1,int ind2,string s1,string s2,vector<vector<int>> &dp){
        if(ind1<0){
            return ind2+1;
        }
        if(ind2<0){
            return ind1+1;
        }

        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        if(s1[ind1]==s2[ind2]){
            return dp[ind1][ind2]=f(ind1-1,ind2-1,s1,s2,dp);
        }

        int a=1+f(ind1,ind2-1,s1,s2,dp);
        int b=1+f(ind1-1,ind2,s1,s2,dp);
        int c=1+f(ind1-1,ind2-1,s1,s2,dp);

        return dp[ind1][ind2]=min(a,min(b,c));
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(n-1,m-1,word1,word2,dp);
    }
};