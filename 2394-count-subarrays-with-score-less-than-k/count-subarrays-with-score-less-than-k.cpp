class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();

        long long sum = 0;
        long long cnt = 0;
        
        int l = 0, r = 0;

        while (r < n) {
            sum+=nums[r];
            
            while (l<=r && sum*(r-l+1)>=k) { 
                sum-=nums[l];
                l++;
            }

            cnt+=(r-l+1); // count subarrays ending at r
            
            r++;
        }

        return cnt;
    }
};
