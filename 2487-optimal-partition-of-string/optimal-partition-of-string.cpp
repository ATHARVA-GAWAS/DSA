class Solution {
public:
    int partitionString(string s) {
        int ans=0;
        map<char,int> mp;

        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                mp.clear();
                ans++;
                mp[s[i]]++;
            }
            else{
                mp[s[i]]++;
            }
        }
        return ans+1;
    }
};