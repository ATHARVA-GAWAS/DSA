class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int n=nums.size();
        int mod=1000000007;
        priority_queue<int,vector<int>,greater<int>> pq;

        for(auto it:nums){
            pq.push(it);
        }

        while(k--){
            int x=pq.top();
            pq.pop();
            x++;
            pq.push(x);
        }

        long long prod=1;

        while(!pq.empty()){
            prod=(prod*pq.top())%mod;
            pq.pop();
        }

        return prod%mod;
    }
};