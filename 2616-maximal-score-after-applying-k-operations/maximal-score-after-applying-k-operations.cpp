class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n=nums.size();

        priority_queue<int> pq;

        for(auto it:nums){
            pq.push(it);
        }

        long long ans=0;

        while(k--){
            long long temp=pq.top();
            ans+=temp;
            pq.pop();

            pq.push(ceil(double(temp/3.0)));
        }        

        return ans;
    }
};