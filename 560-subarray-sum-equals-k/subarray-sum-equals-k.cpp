class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int cursum=0,ans=0;

        mp[0]=1;

        for(int i=0;i<nums.size();i++){
            cursum+=nums[i];

            if(mp.find(cursum-k)!=mp.end()){
                ans+=mp[cursum-k];
            }
            mp[cursum]++;
        }
        return ans;
    }

};