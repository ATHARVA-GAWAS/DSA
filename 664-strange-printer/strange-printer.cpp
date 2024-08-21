class Solution {
public:
    int n;
    
    int f(int l, int r, string& s,vector<vector<int>>&dp){
        if(l == r){
            return 1;
        }
            
        else if(l > r){
            return 0;
        }
        
        if(dp[l][r]!=-1){
            return dp[l][r];
        }

        int i = l+1;
        while(i <= r && s[i] == s[l]){
            i++;
        }
            
        if(i == r+1){
            return 1;
        }
            

        int normal = 1 + f(i,r,s,dp);

        int next = INT_MAX;

        for(int j = i; j <= r; j++){
            if(s[l] == s[j]){
                
                int x = f(i,j-1,s,dp) + f(j,r,s,dp);
                
                next = min(next, x);
            }
        }

        return dp[l][r]=min(next, normal);
    }

    int strangePrinter(string s) {
        n = s.length() ;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(0, n-1, s,dp);
    }
};