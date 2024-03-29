class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int left = 0, right = 0, size = nums.size();
        int maxEle = *max_element(nums.begin(), nums.end());
        int maxEleCnt = 0;
        long long subArrCnt = 0;
        while(right < size){
           if(nums[right++] == maxEle){
               maxEleCnt++;
           }
           while(maxEleCnt == k){
              if(nums[left++] == maxEle)maxEleCnt--;
           }
           subArrCnt += left;
        }
        return subArrCnt;
    }
};