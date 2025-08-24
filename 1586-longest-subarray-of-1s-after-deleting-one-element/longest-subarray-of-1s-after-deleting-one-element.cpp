class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();

        int l=0,r=0;

        int len=0,maxlen=0;

        int zeroes=0;

        while(r<n){
            if(nums[r]==0){
                zeroes++;           
            }

            while(zeroes>1){
                if(nums[l]==0){         //shift the window of zeroes are more than 1
                    zeroes--;
                }
                l++;
            }

            len=r-l+1;
            maxlen=max(maxlen,len);

            r++;
        }

        return maxlen-1;        // we subtract 1 to return the length after deletion of a single 0
    }
};