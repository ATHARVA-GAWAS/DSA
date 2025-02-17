class Solution {
    void f (vector<int> &freq,int &ans) {
        for (int i=0; i<26; i++) {

            if (freq[i] > 0) {
                freq[i]--;
                ans++;
                f(freq,ans);
                freq[i]++;
            }
            
        }
    }
public:
    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);
        int ans=0;

        for (char ch: tiles){
            freq[ch-'A']++;
        } 

        f(freq,ans);

        return ans;
    }
};