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

        long long ans=1;

        while(!pq.empty()){
            ans = (ans * pq.top()) % mod;;
            pq.pop();
        }
        
        return ans%mod;
    }
};