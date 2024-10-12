class Solution {
    int search(std::vector<int>& nums, int target, bool isFirstIndex) {
        int ans = -1;
        int first = 0;
        int last = nums.size() - 1;

        while (first <= last) {
            int mid = first + (last - first) / 2;
            if (target > nums[mid]) {
                first = mid + 1;
            } else if (target < nums[mid]) {
                last = mid - 1;
            } else {
                ans = mid;
                if (isFirstIndex) {
                    last = mid - 1;
                } else {
                    first = mid + 1;
                }
            }
        }
        return ans;
    }
public:
    vector<int> targetIndices(std::vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<int> ans;

        int end;
        int start = search(nums, target, true);

        if (start == -1) {
            return ans;
        } else {
            end = search(nums, target, false);
        }

        for (int i = start; i <= end; i++) {
            ans.push_back(i);
        }
        return ans;
    }
};
