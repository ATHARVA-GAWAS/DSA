class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int pref_size = pref.length();

        int cnt=0;

        for (auto& word : words) {
            if (word.size() >= pref_size && word.starts_with(pref)) {
                cnt++;
            }
        }

        return cnt;
    }
};