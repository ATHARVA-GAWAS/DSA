class Solution {
    int f(int n, int k){
        if(n == 1){
            return 0;
        }
        return (f(n-1, k) + k)%n;
    }
public:
    int findTheWinner(int n, int k) {
        
        int ans = f(n, k) + 1;
        return ans;
    }
};