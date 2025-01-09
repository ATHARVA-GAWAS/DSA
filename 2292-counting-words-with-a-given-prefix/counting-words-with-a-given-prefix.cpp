class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int pref_size = pref.length();

        int cnt=0;

        for (auto& word : words) {
            if (word.size() >= pref_size && word.compare(0, pref_size, pref) == 0) {
                cnt++;
            }
        }

        return cnt;
    }
};