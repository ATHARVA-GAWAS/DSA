class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        
        vector<int> prev(n + 1, 0), cur(n + 1, 0);

        for (int j = 1; j <= n; j++) {
            prev[j] = j;
        }

        for (int i = 1; i <= m; i++) {
            cur[0] = i;
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    cur[j] = prev[j - 1];
                } else {
                    cur[j] = min(prev[j - 1], min(cur[j - 1], prev[j])) + 1;
                }
            }
            prev=cur;
        }
        return prev[n];
    }
};