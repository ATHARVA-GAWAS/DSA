class Solution {
    bool f(vector<int>& piles, int start,int end, bool turn,vector<vector<int>> &dp){
        if(start>end){
            return 0;
        }

        if(dp[start][end]!=-1){
            return dp[start][end];
        }

        if(turn){
            int a=f(piles,start+1,end,false,dp)+piles[start];

            int b=f(piles,start,end-1,false,dp)+piles[end];

            return dp[start][end]=max(a,b);
        }
        int a=f(piles,start+1,end,true,dp)-piles[start];
        int b=f(piles,start,end-1,true,dp)-piles[end];

        return dp[start][end]=max(a,b);
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        
        int start=0;
        int end=piles.size()-1;

        bool turn=true;

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return f(piles,start,end,turn,dp);
    }
};