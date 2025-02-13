class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();

        priority_queue<long long,vector<long long>,greater<long long>> pq;

        for(auto it: nums){
            pq.push(it);
        }

        int cnt=0;

        while(!pq.empty() && pq.top()<k){
            long long x=pq.top();
            pq.pop();

            long long y=pq.top();
            pq.pop();

            long long temp=min(x,y)*2+max(x,y);

            pq.push(temp);
            cnt++;
        }

        return cnt;
    }
};