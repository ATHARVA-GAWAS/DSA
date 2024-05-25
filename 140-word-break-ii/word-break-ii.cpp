class Solution {
public:
   

    void f(int idx, unordered_set<string> &dictSet, string &s, string temp, vector<string> &ans) {
        if (idx == s.length()) {
            temp.pop_back();  // Trim trailing space
            ans.push_back(temp);
            return;
        }

        string currentWord = "";
        for (int i = idx; i < s.length(); i++) {
            currentWord += s[i];
            if (dictSet.find(currentWord) != dictSet.end()) {
                f(i + 1, dictSet, s, temp + currentWord + " ",ans);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& dict) {
        vector<string> ans;
        unordered_set<string> dictSet(dict.begin(), dict.end());  // O(1) lookup
        f(0, dictSet, s, "",ans);
        return ans;
    }
};