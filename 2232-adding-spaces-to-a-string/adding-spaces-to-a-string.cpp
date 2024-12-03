class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n=s.size();

        unordered_set<int> st;
        string ans="";

        for(auto it:spaces){
            st.insert(it);
        }

        for(int i=0;i<n;i++){
            if(st.find(i)!=st.end()){
                ans+=" ";
            }
            ans+=s[i];
        }

        return ans;
    }
};