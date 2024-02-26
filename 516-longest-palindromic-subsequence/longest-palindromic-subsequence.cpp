class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string s2=s;
        reverse(s.begin(),s.end());
        vector<int> prev(n+1,0),cur(n+1,0);

        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(s[ind1-1]==s2[ind2-1]){
                    cur[ind2]=1+prev[ind2-1];
                }
                else{
                    cur[ind2]=max(prev[ind2],cur[ind2-1]);
                }
            }
            prev=cur;
        }
        return prev[n];
    }
};