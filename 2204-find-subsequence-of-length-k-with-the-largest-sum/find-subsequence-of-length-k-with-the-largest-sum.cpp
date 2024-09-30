class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();

        priority_queue<pair<int,int>> pq;

        for(int i=0;i<n;i++){
            auto p=make_pair(nums[i],i);
            pq.push(p);
        }

         vector<pair<int,int>>v;
            while(k--)
            {
                v.push_back({pq.top().second,pq.top().first});
                pq.pop();
            }
            sort(v.begin(),v.end());
            
            vector<int> ans;
            for(auto i :v)
            {
                ans.push_back(i.second);
            }
        return ans;
    }
};