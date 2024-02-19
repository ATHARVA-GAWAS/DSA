class Solution {
    int f(int ind,int end,vector<int>&nums,vector<int>&dp){
        if(ind == end) return nums[end]; 
        if( ind  < end ) return 0; 
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int pick = nums[ind] + f(ind-2,end,nums,dp);  
        int notPick = 0 + f(ind-1,end,nums,dp);

        return  dp[ind]=max(pick, notPick); 
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if( n == 1 ) {
            return nums[0];
        }
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        int case1 = f(n-2,0,nums,dp1); 
        int case2 = f(n-1,1,nums,dp2);  
        return max(case1, case2);
    }
};