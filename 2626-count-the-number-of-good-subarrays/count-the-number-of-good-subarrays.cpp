class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_map<int,int> mp;

        long long result = 0, pairs=0;

        int r=0, l=0;

        while(r<n){
            pairs+=mp[nums[r]];
            
            mp[nums[r]]++;

            while(pairs>=k){
                result+=(n-r);

                mp[nums[l]]--;
                
                pairs-=mp[nums[l]];

                l++;
            }

            r++;
        }

        return result;
    }
};