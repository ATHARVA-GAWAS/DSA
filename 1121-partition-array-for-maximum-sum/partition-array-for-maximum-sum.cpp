class Solution {
    int f(int ind, int n,int k,vector<int>& arr,vector<int> &dp){
        if(ind==n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int len=0,maxele=INT_MIN,maxAns=INT_MIN;
        for(int j=ind;j<min(ind+k,n);j++){
            len++;
            maxele=max(arr[j],maxele);
            int sum=maxele*len+f(j+1,n,k,arr,dp);
            maxAns=max(maxAns,sum);
        }
        return dp[ind]=maxAns;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,-1);
        return f(0,n,k,arr,dp);
    }
};