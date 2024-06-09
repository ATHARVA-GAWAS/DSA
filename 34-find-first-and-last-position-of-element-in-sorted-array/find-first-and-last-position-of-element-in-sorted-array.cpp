class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lower_bound(nums.begin(), nums.end(), target)- nums.begin();
        int last = upper_bound(nums.begin(), nums.end(), target)- nums.begin()-1;

        if (first <= last)
            return {first, last};
            
        return {-1,-1};
    }
};