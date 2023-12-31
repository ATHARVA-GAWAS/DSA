class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n=s.size();
        int maxdiff=-1;
        for(int i=0;i<n;i++){
            int diff=0;
            for(int j=n-1;j>i;j--){
                if(s[i]==s[j]){
                    diff= j-i-1;
                    maxdiff=max(maxdiff,diff);
                }
            }
        }
        return maxdiff;
    }
};