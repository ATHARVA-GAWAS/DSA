class Solution {
public:
    int solve(int ptr,int i, string &ring,string &key,vector<vector<int>> &dp){
        if(i==key.size())   return 0;

        if(dp[ptr][i]!=-1)  return dp[ptr][i];
        
        int ans = 1e9;
        for(int j=0;j<ring.size();j++){
            if(ring[j]==key[i]){
                int steps = min(abs(ptr-j),(int)ring.size()-abs(ptr-j)) + 1;
                ans = min(ans,steps+solve(j,i+1,ring,key,dp));
            }
        }
        return dp[ptr][i] = ans;
    }
    int findRotateSteps(string ring, string key) {
        int n=ring.size(),m=key.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0, ring,key,dp);
    }
};