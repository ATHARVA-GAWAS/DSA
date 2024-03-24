class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int ans=-1;
        for(int it:nums){
            mp[it]++;
            if(mp[it]==2){
                ans=it;
                break;
            }
        }
        return ans;
    }
};