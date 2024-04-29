class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x=0, res=0;
        // Calculate the XOR of all elements in the array
        for(int& a:nums)
            x ^= a;
        
        // Iterate until both x and k become 0
        while(x || k){
            // Check if the least significant bits of x and k are different
            if((x&1) != (k&1))
                res++;
            
            // Right shift x and k to check the next bit
            x >>= 1;
            k >>= 1;
        }

        return res;
    }
};