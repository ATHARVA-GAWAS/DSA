class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int l=0, r=0, size = nums.size();

        int maxEle = *max_element(nums.begin(), nums.end());

        int maxEleCnt = 0;

        long long subArrCnt = 0;

        while(r<size){
           if(nums[r++] == maxEle){
               maxEleCnt++;
           }
           while(maxEleCnt == k){
              if(nums[l++] == maxEle){
                maxEleCnt--;
              }
           }
           subArrCnt += l;
        }

        return subArrCnt;
    }
};