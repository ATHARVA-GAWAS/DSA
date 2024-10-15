class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();

        long long ans=0;

        int l=0,r=n-1;

        while(l<r){
            if(s[l]=='1' && s[r]=='0'){
                swap(s[l],s[r]);
                ans+=r-l;
                l++;
                r--;
            }
            else if(s[r]=='1'){
                r--;
            }
            else{
                l++;
            }
        }

        return ans;
    }
};