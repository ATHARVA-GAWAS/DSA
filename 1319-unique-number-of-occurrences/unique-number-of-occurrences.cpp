class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n=arr.size();
        for(auto it: arr){
            mp[it]++;
        }
        unordered_map<int,int> cnt;
        for(auto it:mp){
            cnt[it.second]++;
        }
        for(auto it:cnt){
            if(it.second>1){
                return false;
            }
        }
        return true;

    }
};