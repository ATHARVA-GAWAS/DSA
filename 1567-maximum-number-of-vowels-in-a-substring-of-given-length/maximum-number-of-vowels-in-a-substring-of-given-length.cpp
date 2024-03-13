class Solution {
    bool is_vowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            return true;
        
        return false;
    }
public:
    int maxVowels(string s, int k) {
        int maxi=INT_MIN;
        int i=0;
        int cnt=0;
        while(i<k){
            if(is_vowel(s[i])){
                cnt++;
            }
            i++;
        }
        int ans=cnt;
        for(int i=k;i<s.size();i++){
            if(is_vowel(s[i])){
                cnt++;
            }
            if(is_vowel(s[i-k])){
                cnt--;
            }
            ans=max(ans,cnt);
        }
       return ans;
    }
};