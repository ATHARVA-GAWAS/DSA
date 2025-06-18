class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int> prefsum(n+1,0);

        int cnt=0;

        for(int i=0;i<n;i++){
            prefsum[i+1]=prefsum[i]+nums[i];
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(prefsum[j]-prefsum[i]==k){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};