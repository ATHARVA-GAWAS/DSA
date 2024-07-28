class Solution {
    int f(vector<int>& nums, int k){
        int l=0,r=0,n=nums.size(),sum=0,cnt=0;

        while(r<n){
            sum+=(nums[r]%2);

            while(sum>k){
                sum=sum-(nums[l]%2);
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }

        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums,k) - f(nums,k-1);
    }
};