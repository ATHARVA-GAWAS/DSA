class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans;
        int l=0,r=nums.size()-1;

        while(l<=r){
            int mid=(l+r)/2;
            if(target==nums[mid]){
                return mid;
            }
            else if(target<nums[mid]){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};