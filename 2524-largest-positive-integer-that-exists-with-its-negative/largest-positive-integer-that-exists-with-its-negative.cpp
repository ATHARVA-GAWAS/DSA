class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0,r=n-1;

        while (l < r) {
            if ((nums[l] + nums[r]) == 0) {
                return nums[r];
            }
            else if ((nums[l] + nums[r]) < 0)
                l++;
            else
                r--;
        }
        return -1;
    }
};