class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,n=s.size(),len=0,maxlen=0;
        unordered_set<char>st;

        while(r<n){
            if(st.find(s[r])!=st.end()){
                while(l<r && st.find(s[r])!=st.end()){
                    st.erase(s[l]);
                    l++;
                }
            }
            st.insert(s[r]);
            len=r-l+1;
            maxlen=max(maxlen,len);
            r++;
        }
        return maxlen;
    }
};