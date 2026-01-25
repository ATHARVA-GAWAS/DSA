class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();

        sort(nums.begin(),nums.end());

        int l=0,r=k-1;

        int diff=0,mini=INT_MAX;

        while(r<n){

            diff=nums[r]-nums[l];

            mini=min(diff,mini);

            r++;
            l++;
        }

        return mini;
    }
};