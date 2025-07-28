class Solution {
public:
    int f(int i,int ors,int maxi,vector<int>& nums) {
        int n=nums.size();

        if(i>=n){
            return (ors==maxi)?1:0;
        }

        int cnt = 0;

        cnt+=f(i+1,ors|nums[i],maxi,nums);
        
        cnt+=f(i+1,ors,maxi,nums);
        
        return cnt;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;
        
        // Calculate the maximum OR value from all elements
        for(auto it: nums){
            maxi =maxi | it;
        }

        return f(0,0,maxi,nums);
    }
};