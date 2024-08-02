class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int cntOnes=0,totOnes=0,maxi=0,r=0,l=0;

        vector<int> temp(2*n);

        for(int i=0;i<2*n;i++){
            temp[i]=nums[i%n];
        }

        for(int i=0;i<n;i++){
            if(nums[i]==1){
                totOnes+=nums[i];
            }
        }
        while(r<2*n){
            if(temp[r]==1){
                cntOnes++;
            }
            
            while(r-l+1>totOnes){
                cntOnes=cntOnes-temp[l];
                l++;
            }
            maxi=max(maxi,cntOnes);
            r++;
        }
        return totOnes-maxi;
    }
};