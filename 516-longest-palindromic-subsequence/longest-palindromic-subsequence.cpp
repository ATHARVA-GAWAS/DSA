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
        vector<int> prev(n+1,0),cur(n+1,0);
        
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                 if(s[ind1-1]==s2[ind2-1]){
                  cur[ind2]= 1+prev[ind2-1];
               }
               else{
                    cur[ind2]=max(prev[ind2],cur[ind2-1]);
               }
              
            }
            prev=cur;
        }
        return prev[n];

    }
};