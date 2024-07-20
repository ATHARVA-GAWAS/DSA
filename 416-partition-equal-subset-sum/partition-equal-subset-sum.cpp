class Solution {
    int f(int ind,int target,vector<int>& nums,vector<vector<int>>&dp){
        if(target==0){
            return true;
        }

        if(ind==0){
            return nums[ind]==target;
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
        int sum=0;

        int n=nums.size();

        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));

        if(sum%2==1){
            return false;
        }

        return f(n-1,sum/2,nums,dp);
    }
};