class Solution {
public:
    int totalMoney(int n) {
        if(n<=7){
            return n*(n+1)/2;
        }

        int weeks = n / 7;
        int rem_days = n % 7;

        int cnt = 1;    // Monday start value
        int x = 1;      // Next week's Monday start
        int ans = 0;

        while(weeks--){
            for(int i = 0; i < 7; i++){
                ans += (cnt + i);
            }
            x++;
            cnt = x;
        }

        // handle remaining days
        for(int i = 0; i < rem_days; i++){
            ans += (cnt + i);
        }

        return ans;
    }
};
