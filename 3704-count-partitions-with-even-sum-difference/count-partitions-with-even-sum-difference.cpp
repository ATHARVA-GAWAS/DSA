class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();

        vector<int> pref(n,0);

        pref[0]=nums[0];

        int totsum=nums[0];

        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];

            totsum+=nums[i];
        }

        int cnt=0;

        for(int i=0;i<n-1;i++){
            int leftsum=pref[i];

            int rightsum=totsum-leftsum;

            if(leftsum%2==rightsum%2){
                cnt++;
            }
        }

        return cnt;
    }
};