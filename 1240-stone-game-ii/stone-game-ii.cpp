class Solution {
    int n;
    int f(int person,int ind,int m,vector<int>&piles,vector<vector<vector<int>>> &dp){
        if(ind>=n){
            return 0;
        }

        //person=1 is Alice, person=2 is Bob

        if(dp[person][ind][m]!=-1){
            return dp[person][ind][m];
        }

        int res=(person==1)?INT_MIN:INT_MAX;

        int stones=0;

        for(int x=1;x<=min(2*m,n-ind);x++){
            stones+=piles[ind+x-1];
            if(person==1){
                res=max(res,stones+f(0,ind+x,max(m,x),piles,dp));
            }
            else{
                res=min(res,f(1,ind+x,max(m,x),piles,dp));
            }
        }
        return dp[person][ind][m]=res;
    }
public:
    int stoneGameII(vector<int>& piles) {
        n=piles.size();

        vector<vector<vector<int>>> dp(2,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return f(1,0,1,piles,dp);
    }
};