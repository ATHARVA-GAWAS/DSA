class Solution {
public:

    void update(int number, vector<int>& vec, int val) {
        for(int i = 0; i < 32; i++) { //O(32)
            if((number >> i) & 1) {
                vec[i] += val;
            }
        }
    }

    int getDecimalFromBinary(vector<int>& vec) {
        int num = 0;

        for(int i = 0; i < 32; i++) { //O(32)
            if(vec[i] > 0) { //ith position has 1
                num |= (1 << i);
            }
        }

        return num;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int result = INT_MAX;

        int l = 0;
        int r = 0;

        vector<int> vec(32, 0);
        //vec[i] = total number of set bits in ith position

        //T.C : O(2*n)
        while(r < n) { //O(n)
            update(nums[r], vec, 1); //adding in the current window

            while(l <= r && getDecimalFromBinary(vec) >= k) {
                result = min(result, r-l+1);
                update(nums[l], vec, -1); //remove the nums[i] from the window
                l++;
            }

            r++;
        }

        return result == INT_MAX ? -1 : result;
    }
};