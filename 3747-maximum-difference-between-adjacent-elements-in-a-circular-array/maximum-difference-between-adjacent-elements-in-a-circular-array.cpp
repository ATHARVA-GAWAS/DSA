class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();

        int maxdiff=INT_MIN;

        for(int i=0;i<n;i++){
            int diff=abs(nums[i]-nums[(i+1)%n]);
            maxdiff=max(maxdiff,diff);
        }

        return maxdiff;
    }
};