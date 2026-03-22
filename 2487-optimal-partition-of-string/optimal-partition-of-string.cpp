class Solution {
public:
    int partitionString(string s) {
        int n=s.size();

        map<char,int> mp;

        int ans=0;

        for(int i=0;i<n;i++){
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