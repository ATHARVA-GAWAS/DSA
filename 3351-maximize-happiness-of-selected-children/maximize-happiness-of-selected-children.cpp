class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

        sort(begin(happiness), end(happiness), greater<int>());

        long long ans = 0;
        
        int count = 0;
        
        for(int i = 0; i < k; i++) {
            ans += max(happiness[i] - count, 0);
            count++;
        }
        
        return ans;
    }
};