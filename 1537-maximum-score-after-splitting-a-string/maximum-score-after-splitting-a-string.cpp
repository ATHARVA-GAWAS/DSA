class Solution {
public:
    int maxScore(string s) {
        int n=s.size();

        int res = INT_MIN;

        for(int i=0;i<n-1;i++){
            int left_zero=0;
            int right_one=0;

            for(int j=0;j<=i;j++){
                if(s[j]=='0'){
                    left_zero++;
                }
            }

            for(int j=i+1;j<n;j++){
                if(s[j]=='1'){
                    right_one++;
                }
            }

            res=max(res,left_zero+right_one);
        }
        return res;
    }
};