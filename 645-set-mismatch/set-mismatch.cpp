class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for(int it:nums){
            mp[it]++;
        }
        vector<int> ans;
        for(auto it:mp){
            if(it.second==2){
                ans.push_back(it.first);
                break;
            }
        }
        int cnt=1;
        for(int i=0;i<n;i++){
            if(cnt==nums[i]){
                 cnt++;
            }
        }
        ans.push_back(cnt);
        return ans;
    }
};