class Solution {
public:
     int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;
        int n=nums.size();
        int len=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
           if(nums[i]==0)
               sum--;
            else
                sum++;
            if(!m.empty() && m.find(sum)!=m.end())
                len=max(len,i-m[sum]);
            if(sum==0)
                len=i+1;
            if(m.find(sum)==m.end())
                m[sum]=i;
                
        }
        return len;
    }
};