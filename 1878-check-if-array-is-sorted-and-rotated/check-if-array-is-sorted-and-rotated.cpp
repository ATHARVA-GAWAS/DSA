class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0, n = nums.size();
        
        //The problem asks us to check if an array can become sorted after performing at most one rotation. Think of it like a circular array where we need to find "breaks" in the ascending pattern
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]){
                count++;          
            }
                
            if (count > 1){
                return false;
            }     
        }
        
        return true;
    }
};