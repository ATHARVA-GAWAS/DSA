class Solution {
public:
    const long long LIMIT = 1000000LL + 5;

    long long countWays(vector<int>& half, int len) {
        long long res = 1;

        // nCr based counting with cap at LIMIT
        int rem = len;

        for (int i = 0; i < 26; i++) {
            int f = half[i];
            if (f == 0) continue;

            long long cur = 1;

            for (int j = 1; j <= f; j++) {
                cur = cur * (rem - f + j) / j;
                if (cur > LIMIT) cur = LIMIT;
            }

            res *= cur;
            if (res > LIMIT) res = LIMIT;

            rem -= f;
        }

        return res;
    }

    string smallestPalindrome(string s, int k) {

        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> half(26, 0);
        
        string center = "";

        int len = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2)
                center.push_back(char('a' + i));

            half[i] = freq[i] / 2;
            len += half[i];
        }

        if (countWays(half, len) < k)
            return "";

        string left = "";

        while (len) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;

                long long ways = countWays(half, len - 1);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    len--;

                    break;
                }

                k -= ways;

                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + center + right;
    }
};