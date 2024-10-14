class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n=nums.size();
        
        long long ans=0;

        priority_queue<int> pq;

        for(auto it:nums){
            pq.push(it);
        }

        int x=k;

        while(x--){
            long long y=pq.top();

            ans+=y;

            pq.pop();

            y=ceil(double(y/3.0));

            pq.push(y);
        }

        return ans;
    }
};