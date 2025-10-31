class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,int> mp;

        for(auto it:nums){
            mp[it]++;
        }

        vector<int> ans;

        for(auto it:mp){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};