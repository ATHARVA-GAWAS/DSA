class Solution {
public:

    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        
        for(int i = 0; i < nums.size(); i++) {
            // If the value at the index abs(nums[i]) - 1 is negative, it means we have encountered this value before
            if(nums[abs(nums[i]) - 1] < 0) {
                // Add the absolute value of nums[i] to the result vector as it is a duplicate
                res.push_back(abs(nums[i]));
            }
            
            // Mark the element at index abs(nums[i]) - 1 as negative, indicating it has been encountered
            nums[abs(nums[i]) - 1] = -1 * nums[abs(nums[i]) - 1];
        }
        
        return res;
    }
};