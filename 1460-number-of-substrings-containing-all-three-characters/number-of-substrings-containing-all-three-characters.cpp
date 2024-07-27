class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i = 0, j = 0, ans = 0;
        int lastseen[3]={-1,-1,-1};

        for(int i=0;i<n;i++){
            lastseen[s[i]-'a']=i;
            if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1){
                ans=ans+(1+min(lastseen[0],min(lastseen[1],lastseen[2])));
            }
        }
        return ans;
    }
};