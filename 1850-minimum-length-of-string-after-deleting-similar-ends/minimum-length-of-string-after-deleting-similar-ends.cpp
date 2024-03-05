class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int i=0;
        int j=n-1;
        int len=n-1;
        while(i<j){
            if(s[i]!=s[j] ){
                break;
            }
            
            char c=s[i];
            while((i<=j) && (s[i]==c)){
                i++;
            }
            while((i<=j) && (s[j]==c)){
                j--;
            }
        }
        if (i <= j) return (j - i + 1);
        return 0;
    }
};