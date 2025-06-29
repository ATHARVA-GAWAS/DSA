class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,int> freq;

        for(auto it:nums){
            freq[it]++;
        }

        int maxlen=0;

        for(auto it:freq){
            if(freq.count(it.first+1)){
                maxlen=max(maxlen,it.second+freq[it.first+1]);
            }
        }

        return maxlen;
    }
};