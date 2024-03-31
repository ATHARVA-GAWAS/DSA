class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();

        int l=0,r=0;

        long long ans=0;

        int mini=-1,maxi=-1;

        while(r<n){
           if(nums[r]<minK || nums[r]>maxK){
              l=r+1;
              mini=-1;
              maxi=-1;
           }
           else{
              if(nums[r]==minK){
                 mini=r;
              }
              if(nums[r]==maxK){
                 maxi=r;
              }
             ans+=max(0,min(mini,maxi)-l+1);
           }
           r++;
        }
        return ans;
    }
};