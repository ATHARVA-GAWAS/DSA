class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();

        vector<int> prev(n2+1,0),cur(n2+1,0);

        for(int ind1=1;ind1<=n1;ind1++){
            for(int ind2=1;ind2<=n2;ind2++){
                int x=0,y=0,z=0;

                if(text1[ind1-1]==text2[ind2-1]){
                    x=1+prev[ind2-1];
                }
                else{
                    y=prev[ind2];
                    z=cur[ind2-1];
                }

                cur[ind2]=max(x,max(y,z));
            }
            prev=cur;
        }
        
        return prev[n2];
    }
};