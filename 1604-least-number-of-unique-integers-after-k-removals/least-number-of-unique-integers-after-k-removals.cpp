class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& nums, int k) {
        vector<int> freq;
        unordered_map<int,int>mp;
        for(int x:nums){
            mp[x]++;
        }
        for(auto x:mp){
            freq.push_back(x.second);
        }
        sort(freq.begin(),freq.end());
        int size=freq.size();
        int s=0;
        while(s<size){
            k-=freq[s];
            if(k<0){
                return size-s;
            }else if(k==0){
                return size-s-1;
            }
            s++;
        }
        return -1;
    }
};