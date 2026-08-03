class Solution {
    long long f(vector<int> &nums, int i, int n, vector<long long> &dp){
        if(i>=n){
            return 0;
        }

        if(dp[i]!=LLONG_MIN){
            return dp[i];
        }
        long long f1=LLONG_MIN, f2=LLONG_MIN, f3=LLONG_MIN;

        f1=nums[i]-f(nums,i+1,n,dp);

        if(i<n-1){
            f2=nums[i]+nums[i+1]-f(nums,i+2,n,dp);
        }
        if(i<n-2){
            f3=nums[i]+nums[i+1]+nums[i+2]-f(nums,i+3,n,dp);
        }

        dp[i]=max(f1,max(f2,f3));
        
        return dp[i];
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();

        vector<long long> dp(n,LLONG_MIN);

        long long diff=f(stoneValue,0,n,dp);

        if(diff>0){
            return "Alice";
        }

        else if(diff==0){
            return "Tie";
        }

        return "Bob";
    }
};