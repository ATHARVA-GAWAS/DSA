class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n=nums.size()/2;

        for (int it:nums) {
            mp[it]++;

            if (mp[it]==n) {
                return it;
            }
        }
        
        return -1;
    }
};
