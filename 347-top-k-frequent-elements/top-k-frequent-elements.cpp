class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_map<int,int> mp;

        for(auto it:nums){
            mp[it]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto it:mp){
            auto p=make_pair(it.second,it.first);

            pq.push(p);
        }

        vector<int> ans;

        for(int i=0;i<k;i++){
            int x=pq.top().second;
            pq.pop();
            ans.push_back(x);
        }

        return ans;
    }
};