class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,long long> freq;

        unordered_map<int, long long> sum;

        vector<long long> ans(n,0);

        for(int i=0;i<n;i++){
            int a=nums[i];

            if(freq[a]){
                ans[i]=freq[a]*i-sum[a];
            }

            freq[a]++;

            sum[a]+=i;
        }

        freq.clear();
        sum.clear();

        for(int i=n-1;i>=0;i--){
            int a=nums[i];

            if(freq[a]){
                ans[i]+=sum[a]-freq[a]*i;
            }

            freq[a]++;

            sum[a]+=i;
        }

        return ans;
    }
};