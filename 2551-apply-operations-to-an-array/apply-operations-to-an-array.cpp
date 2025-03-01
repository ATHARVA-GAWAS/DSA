class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]=nums[i]*2;
                nums[i+1]=0;
            }
        }

        vector<int> ans;
        int cnt_zero=0;

        for(int it:nums){
            if(it==0){
                cnt_zero++;
            }
            else{
                ans.push_back(it);
            }
        }

        while(cnt_zero--){
            ans.push_back(0);
        }

        return ans;
    }
};