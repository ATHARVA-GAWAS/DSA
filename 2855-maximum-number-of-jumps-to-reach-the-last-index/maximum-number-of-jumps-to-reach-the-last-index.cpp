class Solution {
    int f(int i,int target,vector<int>&nums,vector<int> &dp){
        if(i==0){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        int ans=INT_MIN;

        for(int j=0;j<i;j++){
            if(abs(nums[j]-nums[i])<=target){
                ans=max(ans,1+f(j,target,nums,dp));
            }
        }

        return dp[i]=ans;
    }
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        
        vector<int> dp(n,-1);
        int ans= f(n-1,target,nums,dp);

        if(ans<0){
            return -1;
        }

        return ans;
    }
};