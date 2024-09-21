class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size(),l=0,r=0,len=0,maxi=0,zeroes=0;

        while(r<n){
            if(nums[r]==0){
                zeroes++;
            }

            while(zeroes>1){
                if(nums[l]==0){
                    zeroes--;
                }
                l++;
            }
            len=r-l+1;
            maxi=max(maxi,len);
            r++;
        }

        return maxi-1;
    }
};