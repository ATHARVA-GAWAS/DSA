class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();

        int maxlen=1;
        int inc=1,dec=1;

        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                inc+=1;
                dec=1;  //start over again
            }
            else if(nums[i]<nums[i-1]){
                dec+=1;
                inc=1;  //start over again
            }
            else{
                inc=1;
                dec=1;
            }

            maxlen=max(maxlen,max(inc,dec));
        }

        return maxlen;
    }
};