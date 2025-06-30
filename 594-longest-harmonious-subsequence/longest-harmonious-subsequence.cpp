class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());

        int l=0,r=0;

        int maxlen=0;

        while(r<n){
            while(nums[r]-nums[l]>1){
                l++;
            }

            int len=r-l+1;

            if(nums[r]-nums[l]==1){
                maxlen=max(maxlen,len);
            }

            r++;
        }

        return maxlen;
    }
};