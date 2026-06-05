class Solution {
public:
    long long p10(int k) {
        long long x = 1;

        while (k--){
            x *= 10;
        } 

        return x;
    }

    long long helper(int i, int n, const string& limit) {
        if (i >= n - 1) return 0;

        int threshold = stoi(limit.substr(i - 1, 3));

        long long numLeft = (i == 1 ? 0LL : stoll(limit.substr(0, i - 1))) + 1;
        long long numRight = (i == n - 2 ? 0LL : stoll(limit.substr(i + 2))) + 1;

        int numDigitRight = n - i - 2;

        long long base = p10(numDigitRight);
        long long ans = 0;

        int start = (i == 1 ? 100 : 0);

        for (int num = start; num < 1000; num++) {
            int left = num / 100;
            int mid = (num / 10) % 10;
            int right = num % 10;

            bool ok = (mid > left && mid > right) || (mid < left && mid < right);

            if (!ok) continue;

            long long curLeft = (num < 100 ? numLeft - 1 : numLeft);

            if (num > threshold) {
                ans += (curLeft - 1) * base;
            } 
            else if (num == threshold) {
                ans += (curLeft - 1) * base + numRight;
            } 
            else {
                ans += curLeft * base;
            }
        }

        return ans + helper(i + 1, n, limit);
    }

    long long calc(long long x) {
        if (x <= 0){
            return 0;
        } 

        string s = to_string(x);

        return helper(1, (int)s.size(), s);
    }

    long long totalWaviness(long long num1, long long num2) {
        return calc(num2) - calc(num1 - 1);
    }
};