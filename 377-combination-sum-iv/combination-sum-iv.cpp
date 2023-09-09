class Solution {
    int f(int target,vector<int>&nums,vector<int> &dp){
        if (target == 0) {
            return 1;
        }
        if (target < 0) {
            return 0;
        }
        int take = 0;
        if(dp[target]!=-1){
            return dp[target];
        }
       
        for (int j = 0; j < nums.size();j++){
            take += f(target-nums[j],nums,dp); 
        }
        return dp[target]=take;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(target+1,-1);
        return f(target,nums,dp);
    }
};