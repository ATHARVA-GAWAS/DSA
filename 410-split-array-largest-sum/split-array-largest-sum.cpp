class Solution {
    bool cansplit(vector<int>& nums, int mid, int k){
        int n=nums.size();

        int sum=0;
        int subarrays=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>mid){
                subarrays++;
                sum=nums[i];
            }
        }

        return (subarrays+1)<=k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();

        int l=*max_element(nums.begin(),nums.end());

        int r=accumulate(nums.begin(),nums.end(),0);

        int ans=r;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(cansplit(nums,mid,k)){
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