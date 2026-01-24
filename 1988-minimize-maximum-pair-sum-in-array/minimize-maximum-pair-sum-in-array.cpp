class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());

        int l=0,h=n-1;

        int maxres=0;

        while(l<h){
            int sum=nums[l]+nums[h];

            maxres=max(maxres,sum);

            l++;
            h--;
        }

        return maxres;
    }
};