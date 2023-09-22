class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int ind1=1;ind1<=n1;ind1++){
            for(int ind2 = 1;ind2<=n2;ind2++){
                 if(s[ind1-1]==t[ind2-1]){
                     dp[ind1][ind2]=(1+dp[ind1-1][ind2-1]);
                 }
                 else{
                     dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                 }
            }
        }
         int ans=dp[n1][n2];
         if(ans==n1){
             return true;
         }
         return false;
    }
}; 