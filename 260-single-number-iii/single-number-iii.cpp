class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(auto it:nums){
            mp[it]++;
        }

        vector<int> ans;
        for (auto& pair : mp) {
            if (pair.second == 1) {
                ans.push_back(pair.first);
            }
        }

        return ans;
    }
};