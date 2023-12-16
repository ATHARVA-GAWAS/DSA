class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(n!=m){
            return false;
        }
        unordered_map<char,int> mp;
        for(auto it: s){
            mp[it-'a']++;
        }
        for(auto it: t){
            mp[it-'a']--;
        }
        for(auto i:mp){
            if(i.second!=0){
                return false;
            }
        }
        return true;
    }
};