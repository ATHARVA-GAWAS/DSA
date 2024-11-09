class Solution {
public:
    long long minEnd(int n, int x) {
        long long num = x;   //inorder to satisfy the given criteria, we need to have x as a number present, so we let the first number to be x and then perform operations to satisfy the given criteria

        for(int i = 1; i < n; i++) {

            //to check is the next number can be num+1, if not we want to retain the 'one' bits from x so we or them 
            num = (num+1) | x;
            
        }

        return num;
    }
};