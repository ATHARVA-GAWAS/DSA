class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        vector<int> prev(n2+1,0);
        vector<int> cur(n2+1,0);
        for(int ind1=1;ind1<=n1;ind1++){
            for(int ind2 = 1;ind2<=n2;ind2++){
                 if(s[ind1-1]==t[ind2-1]){
                    cur[ind2]=(1+prev[ind2-1]);
                 }
                 else{
                     cur[ind2]=max(prev[ind2],cur[ind2-1]);
                 }
            }
            prev=cur;
        }
         int ans=prev[n2];
         if(ans==n1){
             return true;
         }
         return false;
    }
}; 