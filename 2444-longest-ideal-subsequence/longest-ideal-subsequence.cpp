class Solution {
    int f(string& s,int indx,int prev,int &k,vector<vector<int>>& dp){
        if(indx>=s.size()){
           return 0;
        }
        
        if(dp[indx][prev]!=-1){
           return dp[indx][prev];
        }
        
        
        int take=0,notTake=0;
        if(prev==0 || abs(s[indx]-prev)<=k){
           take=1+f(s,indx+1,s[indx],k,dp);
        }
        
        notTake=0+f(s,indx+1,prev,k,dp);
        
        return dp[indx][prev]=max(take,notTake);
    }
public:
    int longestIdealString(string s, int k) {
       vector<vector<int>>dp (s.size()+1,vector<int>(123,-1));
       return f(s,0,0,k,dp);
    }
};