class Solution {
        int ans;
        unordered_map<int, int> mp;
        void recursion(int ind, int n, vector<int> &tmp, vector<int>& nums, int k) {
        if (ind == n) {
            ans++;
            return;
        }

        // choose the number to the subset
        if (mp[nums[ind] - k] == 0) {
            mp[nums[ind]]++;
            recursion(ind + 1, n, tmp, nums, k);
            mp[nums[ind]]--;
        }   

        // skip the number to the subset
        recursion(ind + 1, n, tmp, nums, k);
        
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        ans = 0;
        vector<int> tmp;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            mp[nums[i]]++;
            recursion(i+1, n, tmp, nums, k);
            mp[nums[i]]--;
        }
        return ans;
    }
};