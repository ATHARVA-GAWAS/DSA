class Solution {
public:
    int maxNumberOfBalloons(string text) {

        int n = text.size();
        map<char,int>mp;

        for(int i = 0 ; i < n ; i++){
            if(text[i] == 'b' || text[i] == 'a' ||text[i] == 'l'||text[i] == 'o'||text[i] == 'n'){
                mp[text[i]]++;
            }
        }
     
        if(mp.size() < 5 || (mp['l'] <= 1) || mp['o'] <= 1){
            return 0;
        }

        int mn = INT_MAX;

        for(auto it : mp){
            mn = min(mn,it.second);
        }

        mn = min({mp['l'] / 2,mp['o'] / 2 , mn});
        
        return mn;
        
    }
};