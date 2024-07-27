class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size(),r=0,l=0,maxlen=0,maxf=0;
        vector<int> mp(26,0);
        while(r<n){
            mp[s[r]-'A']++;
            maxf=max(maxf,mp[s[r]-'A']);
            while((r-l+1)-maxf >k){
                mp[s[l]-'A']--;
                maxf=0;

                for(int i=0;i<26;i++){
                    maxf=max(maxf,mp[i]);
                }
                l++;
            }
            if((r-l+1)-maxf <=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};