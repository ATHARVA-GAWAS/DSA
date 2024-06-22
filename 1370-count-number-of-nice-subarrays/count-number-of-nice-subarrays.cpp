class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ansCnt = 0; 
        int cnt = 0;    
        int l = 0, r = 0; 

        while (r < nums.size()) {
            if (nums[r] % 2 != 0) { 
                k--; 
                cnt = 0;
            }
            
            while (k == 0) { 
                if (nums[l] % 2 != 0) { 
                    k++;
                }
                cnt++;
                l++; 
            }
            
            ansCnt += cnt; 
            r++; 
        }

        return ansCnt; 
    }
};