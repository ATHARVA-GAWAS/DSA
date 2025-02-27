class Solution {
public:
    unordered_map<int,int>mp;
    int f(int j,int k,vector<int>&arr){
        int target=arr[k]-arr[j];
        
        if(mp.count(target) && mp[target]<j){
            int i=mp[target];

            return f(i,j,arr)+1;
        }

        return 2;
    } 

    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        if(n<=2) return 0;
        int ans=0;
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        } 

        for(int j=1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int length=f(j,k,arr);

                if(length>=3){
                    ans=max(ans,length);
                }
            }
        }
        return ans;
    }
};