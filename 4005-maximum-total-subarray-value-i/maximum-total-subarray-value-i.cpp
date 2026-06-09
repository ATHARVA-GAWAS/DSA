class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();

        int mini=INT_MAX;
        int maxi=INT_MIN;

        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }

        long long ans=(maxi-mini)*(long long )k;

        return ans;
    }
};