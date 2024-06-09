class Solution {
    int f(int ind,vector<int>&a,int total,vector<vector<int>> &dp){
        int n=a.size();
        if(ind>=n){
            return total;
        }
        if(dp[ind][total]!=-1){
            return dp[ind][total];
        }
        int take=0,nottake=0;
        if(a[ind]>total){
        
           take =f(ind+1,a,total+a[ind],dp);
        }
        
        nottake=f(ind+1,a,total,dp);
    
     return dp[ind][total]=max(take,nottake);  
    }
public:
    int maxTotalReward(vector<int>& rewardValues) {
       int n=rewardValues.size();
       sort(rewardValues.begin(),rewardValues.end());
       vector<vector<int>> dp(n+1,vector<int>(4002,-1));
       return f(0,rewardValues,0,dp);
       
    }
};