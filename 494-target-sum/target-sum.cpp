class Solution {
    int f(int ind,int target,vector<int>&nums){

        if(ind==0){
            if(nums[ind]==target && target==0){
                return 2;
            }
            if(nums[ind]==target || target==0){
                return 1;
            }
           
            return 0;
        }

        int nottake=f(ind-1,target,nums);

        int take=0;
        
        if(nums[ind]<=target){
            take=f(ind-1,target-nums[ind],nums);
        }
        
        return take+nottake;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totSum = 0;
        int n=nums.size();

        for(int i=0; i<nums.size();i++){
            totSum += nums[i];
        }

        if(totSum-target<0){
            return 0;
        } 
        if((totSum-target)%2==1){
            return 0;
        } 
        
        int s2 = (totSum-target)/2;
        
        return f(n-1,s2,nums);
    }
};