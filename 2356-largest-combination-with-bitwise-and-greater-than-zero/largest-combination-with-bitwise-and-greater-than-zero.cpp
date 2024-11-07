class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> cnt(32,0);

        int res=0;

        for(int i=0;i<32;i++){
            for(int &num:candidates){
                if((num&(1<<i))!=0){
                    cnt[i]++;
                }
            }
            res=max(res,cnt[i]);
        }

        return res;
    }
};