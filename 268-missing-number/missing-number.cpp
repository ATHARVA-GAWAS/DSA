class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int x;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                x=i;
                break;
            }
        }
        return x;
    }
};