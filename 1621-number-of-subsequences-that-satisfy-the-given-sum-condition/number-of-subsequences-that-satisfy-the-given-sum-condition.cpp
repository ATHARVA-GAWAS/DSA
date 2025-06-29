class Solution {
    int MOD=1e9+7;
public:
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();

        sort(nums.begin(),nums.end());

        vector<int> powerof2(n,1);

        // Precompute powers of 2
        for(int i=1;i<n;i++){
            powerof2[i]=(powerof2[i-1]*2*1ll)%MOD;
        }

        int l=0,r=n-1;

        int res=0;

//      If nums[left] + nums[right] <= target:

//      Then all subsequences that include nums[left] and any subset of nums[left+1...right] are valid.

//      Count of such subsequences: 2^(right - left)

//      Increment left.

//      Else, decrement right.

        while(l<=r){
            if(nums[l]+nums[r]<=target){
                res=(res+powerof2[r-l])%MOD;
                l++;
            }
            else{
                r--;
            }
        }

        return res;
    }
};