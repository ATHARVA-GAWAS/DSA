class Solution {
public:
int n;
    int f(int ind, int xorsum, vector<int>& nums){
        if (ind==n){
            return xorsum;
        } 
        int x=nums[ind];

        int take=f(ind+1, xorsum^x, nums);

        int notake=f(ind+1, xorsum, nums);

        return take+notake;
    }
    int subsetXORSum(vector<int>& nums) {
        n=nums.size();
        return f(0, 0, nums);
    }
};