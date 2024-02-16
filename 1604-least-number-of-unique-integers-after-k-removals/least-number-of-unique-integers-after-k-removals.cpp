class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& nums, int k) {
        vector<int> freq;
        unordered_map<int,int>mp;
        for(int x:nums){
            mp[x]++;
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto& it:mp){
            pq.push(it.second);
        }
        while(k>0){
            k=k-pq.top();
            if(k>=0){
                pq.pop();
            }
        }
        return pq.size();
    }
};