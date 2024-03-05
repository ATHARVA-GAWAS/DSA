class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        string ans="";
        if(n<=m){
           for(int i=0;i<m;i++){
               if(i<n){
                   ans+=word1[i];
                   ans+=word2[i];
               }
               else{
                   ans+=word2[i];
               }
           }
        }
        else{
            for(int i=0;i<n;i++){
               if(i<m){
                   ans+=word1[i];
                   ans+=word2[i];
               }
               else{
                   ans+=word1[i];
               }
           }
        }
        return ans;
        
    }
};