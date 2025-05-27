class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

        vector<int> ahead(n+1,0),cur(n+1,0);

        for(int ind=n-1;ind>=0;ind--){
            for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
                 int len=0+ahead[prev_ind+1];

                if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
                    len=max(len, 1+ahead[ind+1]);
                }
                cur[prev_ind + 1] = len;
            }
            ahead=cur;
        }

        return ahead[0];
    }
};