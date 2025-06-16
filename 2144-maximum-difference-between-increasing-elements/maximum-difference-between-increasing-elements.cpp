class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();

        int maxi=-1,small=nums[0];

        for(int i=1;i<n;i++){

            int diff=nums[i]-small;

            if(diff>0){
                maxi = max(maxi,diff);
            } 
            else{
                small = nums[i];
            } 
        }

        return maxi;
    }
};