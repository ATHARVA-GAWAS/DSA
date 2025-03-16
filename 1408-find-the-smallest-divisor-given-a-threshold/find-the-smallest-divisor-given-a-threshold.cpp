class Solution {
    bool candivide(vector<int>& nums, int divisor,int k) {
        int sum = 0;
        for (int num : nums) {
            sum += (num + divisor - 1) / divisor;  // Equivalent to ceil(num / divisor)  
        }
        return sum<=k;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();

        int l = 1, r = *max_element(nums.begin(), nums.end());

        int ans=r;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(candivide(nums,mid,threshold)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return ans;
    }
};