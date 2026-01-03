class Solution {
    int mod=1e9+7;
    int f(int ind,int n,int a,int b,int c,vector<vector<vector<vector<int>>>> &dp){
        if(ind==n){
            return 1;
        }

        if(dp[ind][a][b][c]!=-1){
            return dp[ind][a][b][c];
        }

        int res=0;

        for(int i=1;i<=3;i++){
            if(i==a){
                continue;
            }

            for(int j=1;j<=3;j++){
                if(j==i || j==b){
                    continue;
                }

                for(int k=1;k<=3;k++){
                    if(k==j || k==c){
                        continue;
                    }

                    res=(res+f(ind+1,n,i,j,k,dp))%mod;
                }
            }
        }

        return dp[ind][a][b][c]=res;
    }
public:
    int numOfWays(int n) {
        int res=0;

        vector<vector<vector<vector<int>>>> dp(n+1,vector<vector<vector<int>>>(4,vector<vector<int>>(4,vector<int>(4,-1))));

        res+=f(0,n,0,0,0,dp);

        return res;
    }
};