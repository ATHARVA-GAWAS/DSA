class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();

        int l=0,r=0;

        unordered_set<int> st;

        int sum=0,maxsum=0;

        while(r<n){
            while(st.find(nums[r])!=st.end()){
                sum-=nums[l];
                st.erase(nums[l]);
                l++;
            }

            sum+=nums[r];

            maxsum=max(maxsum,sum);

            st.insert(nums[r]);
            r++;
        }

        return maxsum;
    }
};