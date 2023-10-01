class Solution {
public:
    string reverseWords(string s) {
         stack<char>st;
        string ans="";
        for(int i=0;i<s.size();i++){
          if(s[i]!=' '){
              st.push(s[i]);
          }
          else{
              while(!st.empty()){
                char p=st.top();
                st.pop();
                ans.push_back(p);
              }
              if(ans.size()!=0)
              ans.push_back(' ');
          }
        }
        while(!st.empty()){
                char p=st.top();
                st.pop();
                ans.push_back(p);
        }
        return ans;
    }
};