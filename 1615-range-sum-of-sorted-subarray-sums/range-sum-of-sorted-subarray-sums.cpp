class Solution {
    int mod=1e9+7;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> temp;

        int prefsum,k=0;
        
        for(int i=0;i<n;i++){
            prefsum=0;
            for(int j=i;j<n;j++){
                prefsum+=nums[j];
                temp.push_back(prefsum);
            }
        }
        sort(temp.begin(),temp.end());

        int ans=0;
        for(int i=left-1;i<right;i++){
            ans=(ans+temp[i])%mod;
        }
        return ans%mod;
    }
};