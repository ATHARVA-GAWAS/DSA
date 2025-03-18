class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int l=0;
        int r=0;

        int maxlen=1;
        int mask=0;

        while(r<n) {

            while((mask&nums[r]) != 0) { //keep shrinking
                mask = (mask ^ nums[l]);
                l++;
            }

            int len=r-l+1;

            maxlen = max(maxlen, len);
            mask = (mask | nums[r]);
            r++;
        }

        return maxlen;

    }
};