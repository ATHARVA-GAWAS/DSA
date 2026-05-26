class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();

        unordered_map<int,int> mp;

        for(auto it:word){
            mp[it-'a']++;
        }

        int cnt=0;

        for(auto it:mp){
            if(mp.find(it.first+32)!=mp.end()){
                cnt++;
            }
        }

        return cnt;
    }
};
