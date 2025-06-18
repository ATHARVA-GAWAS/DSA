class Solution {
public:
    int solve(int minV,vector<int>&arr,int k)//Range=[minV,minV+k]
    {
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<minV)
            {
                ans+=arr[i];
                continue;
            }
            if(arr[i]>minV+k)
            {
                ans+=arr[i]-(minV+k);
            }
        }
        return ans;
        
    }
    int minimumDeletions(string word, int k) {
    
        vector<int>freq(26,0);

        for(auto it:word)freq[it-'a']++;
         
        vector<int>arr;

        for(int i=0;i<26;i++)
        {
            if(freq[i]){
                arr.push_back(freq[i]);
            }
        }

        sort(arr.begin(),arr.end());

        int ans=1e9;

        for(int i=0;i<=arr.back();i++)//selecting minV
        {
           ans=min(ans,solve(i,arr,k)); 
        }

        return ans;
    }
};