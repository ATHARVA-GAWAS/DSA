class Solution {
    int f(int ind1,int ind2,string a, string b,vector<vector<int>> &dp){
        if(ind1<0 || ind2<0){
            return 0;
        }

        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }

        int x=0,y=0,z=0;

        if(a[ind1]==b[ind2]){
            x=1+f(ind1-1,ind2-1,a,b,dp);
        }
        else{
            y=f(ind1-1,ind2,a,b,dp);
            z=f(ind1,ind2-1,a,b,dp);
        }

        return dp[ind1][ind2]=max(x,max(y,z));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();

        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

        for(int ind1=1;ind1<=n1;ind1++){
            for(int ind2=1;ind2<=n2;ind2++){
                int x=0,y=0,z=0;

                if(text1[ind1-1]==text2[ind2-1]){
                    x=1+dp[ind1-1][ind2-1];
                }
                else{
                    y=dp[ind1-1][ind2];
                    z=dp[ind1][ind2-1];
                }

                dp[ind1][ind2]=max(x,max(y,z));
            }
        }
        
        return dp[n1][n2];
    }
};