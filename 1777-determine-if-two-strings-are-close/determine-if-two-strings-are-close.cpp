class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        if(m!=n){
            return false;
        }
        vector<int> a1(26);
        vector<int> a2(26);

        for(int i=0;i<m;i++){
            a1[word1[i]-'a']++;
            a2[word2[i]-'a']++;
        }
        //if letters match or not

        for(int i=0;i<26;i++){
            if(a1[i]!=0 && a2[i]!=0){
                continue;
            }
             if(a1[i]==0 && a2[i]==0){
                continue;
            }
            return false;
        }
        
        //if frequency matches
        sort(a1.begin(),a1.end());
        sort(a2.begin(),a2.end());
        return a1==a2;
    }
};