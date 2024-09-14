class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxval=0,res=0,streak=0;

        for(auto it:nums){
            if(it>maxval){
                maxval=it;
                streak=0;
                res=0;
            }

            if(maxval==it){
                streak++;
            }
            else{
                streak=0;
            }

            res=max(res,streak);
        }

        return res;
    }
};