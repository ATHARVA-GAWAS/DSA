class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();

        int ans=0;

        bool flag=true;

        for(int i=0;i<n;i++){
            ans=ans^nums[i];

            if(nums[i]!=0){
                flag=false;
            }
        }

        if(ans==0){
            if(flag){
                return 0;
            }

            return n-1;
        }

        return n;
    }
};