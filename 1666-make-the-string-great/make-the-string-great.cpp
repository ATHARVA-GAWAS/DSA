class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        string ans="";
        for(auto it:s){
            if(st.empty())st.push(it);
            else if(abs(st.top()-it)==32)st.pop();
            else st.push(it);
        }
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};