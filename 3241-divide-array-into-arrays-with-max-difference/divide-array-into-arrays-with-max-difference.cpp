class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();

        sort(nums.begin(),nums.end());

        vector<vector<int>> ans(n/3,vector<int>(3));

        int ind=0;

        for(int i=0;i<n;i+=3){
            if(nums[i+2]-nums[i]<=k){
                ans[ind][0]=nums[i];
                ans[ind][1]=nums[i+1];
                ans[ind][2]=nums[i+2];
                ind++;
            }
            else {
                return vector<vector<int>>(0, vector<int>(0));
            }
        }

        return ans;
    }
};