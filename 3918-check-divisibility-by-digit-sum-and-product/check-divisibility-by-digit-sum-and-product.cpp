class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int prod=1;

        int a=n,b=n;

        while(a){
            sum+=a%10;
            a=a/10;
        }

        while(b){
            prod*=b%10;
            b=b/10;
        }

        return n%(sum+prod)==0;
    }
};