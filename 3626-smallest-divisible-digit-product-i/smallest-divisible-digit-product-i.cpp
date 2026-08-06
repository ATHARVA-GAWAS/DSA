class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<=n+10;i++){
            
            int ans=1;
            int temp=i;

            while(temp>0){
                int rem=temp%10;
                ans*=rem;
                temp/=10;
            }

            if(ans%t==0){
                return i;
            }
        }
        return -1;
    }
};