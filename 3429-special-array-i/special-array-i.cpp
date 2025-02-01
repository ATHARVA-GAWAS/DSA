class Solution {
    bool is_even(int a){
        if(a%2==0){
            return true;
        }
        return false;
    }

    bool is_odd(int a){
        if(a%2!=0){
            return true;
        }
        return false;
    }
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n-1;i++){
            if(is_odd(nums[i]) && is_odd(nums[i+1]) || is_even(nums[i]) && is_even(nums[i+1])){
                return false;
            }
        }

        return true;
    }
};