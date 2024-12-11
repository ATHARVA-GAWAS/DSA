class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();

        sort(nums.begin(),nums.end());

        int maxi=0;
        int r=0,l=0;

        while(r<n){
            while(nums[r]-nums[l]>2*k){
                l++;
            }
            maxi=max(maxi,r-l+1);
            r++;
        }

        return maxi;
    }
};