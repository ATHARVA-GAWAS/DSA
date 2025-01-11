class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();

        if(n<k){
            return false;
        }

        vector<int> freq(26,0);

        for(auto it:s){
            freq[it-'a']++;
        }

        int odd=0;

        for(int i=0;i<26;i++){
            if(freq[i]%2!=0){
                odd++;
            }
        }

        return odd<=k;
    }
};