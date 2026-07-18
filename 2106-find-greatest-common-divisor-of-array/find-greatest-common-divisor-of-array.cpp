class Solution {
    int gcd(int a,int b){
        if(a==0){
            return b;
        }
        if(b==0){
            return a;
        }

        if(a>b){
            return gcd(a-b,b);
        }

        return gcd(a,b-a);
    }
public:
    int findGCD(vector<int>& nums) {
        int n=nums.size();

        int a=INT_MAX,b=INT_MIN;

        for(int i=0;i<n;i++){
            a=min(a,nums[i]);
            b=max(b,nums[i]);
        }

        return gcd(a,b);
    }
};