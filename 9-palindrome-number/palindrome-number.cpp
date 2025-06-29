class Solution {
public:
    bool isPalindrome(int x) {
        string y=to_string(x);

        int n=y.size();

        int l=0,r=n-1;

        while(l<r){
            if(y[l]!=y[r]){
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};