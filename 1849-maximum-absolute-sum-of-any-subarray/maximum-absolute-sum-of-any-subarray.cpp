class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();

        int cursum=nums[0];
        int maxi=nums[0];

        for(int i=1;i<n;i++){
            cursum=max(nums[i],cursum+nums[i]);
            maxi=max(maxi,cursum);
        }

        int mini=nums[0];
        cursum=nums[0];

        for(int i=1;i<n;i++){
            cursum=min(nums[i],cursum+nums[i]);
            mini=min(mini,cursum);
        }

        return max(maxi, abs(mini));
    }
};