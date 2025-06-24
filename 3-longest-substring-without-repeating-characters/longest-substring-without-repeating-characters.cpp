class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        
        int n=s.size();

        int len=0,maxlen=0;

        unordered_map<char,int> mp;

        while(r<n){
            while(mp.find(s[r])!=mp.end()){
                mp[s[l]]--;
                mp.erase(s[l]);
                l++;
            }
            mp[s[r]]++;

            len=r-l+1;

            maxlen=max(maxlen,len);

            r++;
        }


        return maxlen;
    }
};