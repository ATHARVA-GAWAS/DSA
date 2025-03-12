class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int total_elems = nums.size();

        int left = 0, right = total_elems - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < 0) {
                left = mid + 1;
            } 
            else {
                right = mid - 1;
            }
        }

        int neg = left;

        left = 0, right = total_elems - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] <= 0) {
                left = mid + 1;
            }
             else {
                right = mid - 1;
            }
        }
        
        int pos = total_elems - left;

        return max(neg, pos);
    }
};