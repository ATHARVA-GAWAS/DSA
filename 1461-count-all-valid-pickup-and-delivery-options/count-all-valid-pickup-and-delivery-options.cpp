class Solution {
public:
    int countOrders(int n) {
        int mod=1e9+7;
        long total_opt=2*n;
        long ans=1;
        for(int  i=n;i>0;i--){
            ans=(ans*(total_opt*(total_opt-1))/2)%mod;
            total_opt=total_opt-2;
        }
        return (int) ans;
    }
};