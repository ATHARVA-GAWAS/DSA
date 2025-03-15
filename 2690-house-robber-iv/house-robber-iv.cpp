class Solution {
    bool rob(vector<int>&nums,int mid,int k){
        int n=nums.size();

        int house=0;

        for(int i=0;i<n;i++){
            if(nums[i]<=mid){
                house++;
                i++;  //skipping a house
            }
        }

        return house>=k;  //atleast k houses robbed
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();

        int l = *min_element(begin(nums), end(nums));
        int r = *max_element(begin(nums), end(nums));

        int res = r;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(rob(nums,mid,k)){
                res=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return res;
    }
};