class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n=s.size();
        vector<int> cnt(26,-1);
        int maxdiff=-1;
        for(int i=0;i<n;i++){
            int diff=0;
            char ch=s[i];
            if(cnt[ch-'a']==-1){
                cnt[ch-'a']=i;
            }
            else{
                diff= i-cnt[ch-'a']-1;
                maxdiff=max(maxdiff,diff);
            }
            
        }
        return maxdiff;
    }
};
// tc: O(N)  sc= O(26)