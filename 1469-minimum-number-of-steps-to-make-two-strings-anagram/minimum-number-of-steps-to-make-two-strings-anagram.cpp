class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>mp;
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto it: mp){
            if(it.second>0){
                cnt+=it.second;
            }
        }
        return cnt;
    }
};