class Solution {
public:
    int digitsum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        int freq[46] = {0};  // Max digit sum for n <= 10^5 is 45
        int maxFreq = 0;

        for (int i = 1; i <= n; ++i) {
            int sum = digitsum(i);
            freq[sum]++;
            maxFreq = max(maxFreq, freq[sum]);
        }

        int count = 0;
        for (int i = 0; i < 46; ++i) {
            if (freq[i] == maxFreq){
                count++;
            } 
        }

        return count;  
    }
};