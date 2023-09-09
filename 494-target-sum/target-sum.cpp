class Solution {
    int f(int ind,int target,vector<int>& arr,vector<vector<int>>& dp){
        if(ind == 0){
        if(target==0 && arr[0]==0){
               return 2;
        }
            
        if(target==0 || target == arr[0]){
               return 1;
           }
            
        return 0;
    }
    int notTaken = f(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = f(ind-1,target-arr[ind],arr,dp);
        
    return  (notTaken + taken);
    }
public:
    int findTargetSumWays(vector<int>& arr, int target) {
        int totSum = 0;
        int n=arr.size();
    for(int i=0; i<arr.size();i++){
        totSum += arr[i];
    }
    if(totSum-target<0) return 0;
    if((totSum-target)%2==1) return 0;
    
    int s2 = (totSum-target)/2;
    
    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    return f(n-1,s2,arr,dp);
    }
};