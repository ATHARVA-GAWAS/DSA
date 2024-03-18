class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        for(auto it: mp){
            pq.push({it.second,it.first});
        }
        int cnt=k;
        vector<int> ans;
        while(cnt--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};