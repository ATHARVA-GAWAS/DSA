class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        if (n == 0) return 0; 
        if (n == 1) return nums[0];

        vector<int> dp(n+1,0);

        dp[0]=nums[0];
        dp[1] = max(nums[0], nums[1]); // Base case: rob the max of first two houses

        for(int ind=2;ind<n;ind++){
            int rob=nums[ind]+dp[ind-2];
            int dont_rob=dp[ind-1];

            dp[ind]=max(rob,dont_rob);
        }
        return dp[n-1];
    }
};