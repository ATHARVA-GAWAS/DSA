class Solution {
public:
    int evalRPN(vector<string>& tokens) {
         stack<int>st;
        for(int i=0;i<tokens.size();i++){
            string s=tokens[i];
            if(s=="*" || s=="+" || s=="-" || s=="/") {
                int a = st.top(), result;
                st.pop();
                int b = st.top();
                st.pop();
                if(s=="*") result = a*b;
                else if(s=="+") result = a+b;
                else if(s=="-") result = b-a;
                else result = b/a;
                st.push(result);
            } 
            else{
                int x=stoi(s);
                st.push(x);
            }
        }
        return (int)st.top();
    }
};