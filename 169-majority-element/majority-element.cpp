class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }

        sort(nums.begin(),nums.end());

        int cnt=1,ans;

        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                cnt++;
            }
            else{
                cnt=1;
            }
            if(cnt>n/2){
                ans=i;
                break;
            }
        }
        return nums[ans];
    }
};