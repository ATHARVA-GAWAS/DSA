class Solution {
public:
    bool isPossible(long long int mx,int div1,int div2,int u1,int u2){
       
        long long int c1=mx/div1;
        long long int lcm=(long long) div1* (long long )div2/__gcd(div1,div2);
        
        int count=mx/lcm;
        
        long long int c2=mx/div2;
        // if arr1 not feasible
        if(mx-c1<u1){
            return false;
        }
        // if arr2 not feasible
        if(mx-c2<u2){
            return false;
        }
        
        if(mx-count<(u1+u2)){
            return false;
        }
        
        return true;
    }
    int minimizeSet(int div1, int div2, int u1, int u2) {
        long long int end=10000000000;
        long long int start=2;
        int ans=-1;
        while(start<=end){
            long long int mid=start+(end-start)/2;
            
            if(isPossible(mid,div1,div2,u1,u2)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};