class Solution {
public:
    bool winnerOfGame(string colors) {
        int c1=0,c2=0;
        int n=colors.size();
        for(int i=0;i<n;i++){
            if(colors[i]=='A' && colors[i+1]=='A' && colors[i+2]=='A'){
                c1++;
            }
            if(colors[i]=='B' && colors[i+1]=='B' && colors[i+2]=='B'){
                c2++;
            }
        }
        return c1>c2;
    }
};