class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int>> mp;

        for (int i : nums) {
            int sum = 0, n = i;

            while (n) {
                sum += n % 10;
                n /= 10;
            }

            mp[sum].push(i);
        }

        int ans = -1;

        for (auto& it : mp) {
            if (it.second.size() > 1) {
                int sum = it.second.top();
                it.second.pop();

                sum += it.second.top();
                
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};