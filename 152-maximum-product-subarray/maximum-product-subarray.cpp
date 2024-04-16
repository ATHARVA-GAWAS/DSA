class Solution {
public:
    int maxProduct(vector<int>& nums) {
long int n = nums.size();
        if(n==1) {
            return nums[0];
        }
        long int ans1 = INT_MIN;
        long int ans2 = INT_MIN;
        long int prod = 1;

        for(long int i=0;i<n;i++) {
            prod *= nums[i];
        
            if(prod> ans1) {
                ans1 = prod;
            }
            if(prod==0) {
                prod = 1;
            }
        }
        prod = 1;
        for(long int i=n-1;i>=0;i--) {
            prod *= nums[i];
        
            if(prod> ans2) {
                ans2 = prod;
            }
            if(prod==0) {
                prod = 1;
            }
        }
        return max(ans1, ans2);
    }
};