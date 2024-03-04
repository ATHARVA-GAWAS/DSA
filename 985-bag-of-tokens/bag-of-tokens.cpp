class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
        int score=0,ans=0;
        int i=0, j=n-1;
        while(i<=j){
            if(power>=tokens[i]){
                score++;
                ans=max(ans,score);
                power-=tokens[i];
                i++;
            }
            else if(score>0){
                score--;
                power+=tokens[j];
                j--;
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};