class Solution {
    int house_robbery(int ind,vector<int>&nums,vector<int>&dp){
        if(ind<0){
            return 0;
        }

        if(ind==0){
            return nums[ind];
        }

        if(dp[ind]!=-1){
            return dp[ind];
        }

        int rob=nums[ind]+house_robbery(ind-2,nums,dp);
        int dont_rob=nums[ind-1]+house_robbery(ind-3,nums,dp);

        return dp[ind]=max(rob,dont_rob);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        vector<int> dp(n+1,-1);

        return house_robbery(n-1,nums,dp);
    }
};