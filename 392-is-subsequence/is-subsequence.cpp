class Solution {
    int f(int ind1,int ind2,string s,string t,vector<vector<int>> &dp){
        if(ind1<0 || ind2<0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        if(s[ind1]==t[ind2]){
            return dp[ind1][ind2]=(1+f(ind1-1,ind2-1,s,t,dp));
        }
        return dp[ind1][ind2]=max(f(ind1-1,ind2,s,t,dp),f(ind1,ind2-1,s,t,dp));
    }
public:
    bool isSubsequence(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
         int ans=f(n1-1,n2-1,s,t,dp);
         if(ans==n1){
             return true;
         }
         return false;
    }
}; 