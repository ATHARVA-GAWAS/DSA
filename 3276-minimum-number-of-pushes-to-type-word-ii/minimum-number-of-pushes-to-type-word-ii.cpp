class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        int ans = 0;

        for (char c : word) {
            freq[c - 'a']++;
        }

        sort(freq.begin(), freq.end(),greater<int>());

        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (i % 8 == 0) {
                count ++;
            }
            ans += freq[i] * count;
        }

        return ans;
    }
};