class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        int n=nums.size();

        int l=0,r=0,cnt=0;

        while(r<n){
            if(mp.count(nums[r])==0){
                mp[nums[r]]=1;
            }
            else{
                mp[nums[r]]++;
            }
            while(mp[nums[r]]>k){
                mp[nums[l++]]--;
            }
            cnt=max(cnt,r-l+1);
            r++;   
        }
        return cnt;
    }
};