class Solution {
public:
    string minRemoveToMakeValid(string s) {
      stack<int> st;  // unpaired '(' indices

        for (int i = 0; i < s.length(); ++i)
        if (s[i] == '(') {
            st.push(i);  // Record the unpaired '(' index.
        } else if (s[i] == ')') {
            if (st.empty())
            s[i] = '*';  // Mark the unpaired ')' as '*'.
            else
            st.pop();  // Find a pair!
        }

        // Mark the unpaired '(' as '*'.
        while (!st.empty())
        s[st.top()] = '*', st.pop();

        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};