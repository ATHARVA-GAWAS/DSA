class Solution {
public:
    int f(int n, int k, vector<int>&nums){
        int cnt=0,l=0,r=0;
        unordered_map<int,int> mp;

        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;

                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return f(n, k, nums) - f(n, k-1, nums);
    }
};