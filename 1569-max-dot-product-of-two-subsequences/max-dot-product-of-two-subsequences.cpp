class Solution {
public:
int f(int ind1,int ind2,vector<int>& nums1, vector<int>& nums2,vector<vector<int>> &dp){
    if(ind1<0 || ind2<0 ){
        return -1e9;
    }
     if(dp[ind1][ind2]!=-1){
         return dp[ind1][ind2];
     }
    int prod=-1e9;
    prod = max(prod, max( f(ind1-1,ind2-1,nums1,nums2,dp), 0) + nums1[ind1] * nums2[ind2]); //take both
     prod=max(prod,f(ind1,ind2-1,nums1,nums2,dp));  //skip1
     prod=max(prod,f(ind1-1,ind2,nums1,nums2,dp));  //skip2
     return dp[ind1][ind2]=prod;
}
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
          int n=nums1.size();
          int m=nums2.size();
          vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
          return f(n-1,m-1,nums1,nums2,dp);
    }
};