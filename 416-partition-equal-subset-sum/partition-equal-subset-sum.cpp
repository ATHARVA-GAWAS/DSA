class Solution {
    bool f(int ind,int target,vector<int>&nums,vector<vector<int>> &dp){
        if(target==0){
            return true;
        }

        if(ind==0){
            if(nums[ind]==target){
                return true;
            }
            else{
                return false;
            }
        }

        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }

        bool nottaken=f(ind-1,target,nums,dp);
        bool taken=false;

        if(nums[ind]<=target){
            taken=f(ind-1,target-nums[ind],nums,dp);
        }

        return dp[ind][target]=taken||nottaken;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();

        int totsum=0;

        for(auto it:nums){
            totsum+=it;
        }

        if(totsum%2!=0){
            return false;
        }

        vector<vector<int>> dp(n+1,vector<int>(totsum,-1));

        return f(n-1,totsum/2,nums,dp);
    }
};