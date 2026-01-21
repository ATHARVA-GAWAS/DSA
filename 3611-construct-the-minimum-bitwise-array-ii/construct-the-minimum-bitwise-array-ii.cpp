class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 2 == 0){
                nums[i] = -1;
            } 

            else{
                int t = nums[i];
                int count = 0;
                while(t & 1){
                    count++;
                    t = t >> 1;
                }
                nums[i] = nums[i] - pow(2, count - 1);
            } 
        }   
        return nums;
    }
};