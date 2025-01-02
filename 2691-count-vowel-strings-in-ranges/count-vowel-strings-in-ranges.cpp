class Solution {
    bool isvowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;

        int n = words.size();
        vector<int> prefix(n + 1, 0);


        for(int i=0;i<n;i++){
            if(isvowel(words[i][0]) && isvowel(words[i].back())){
                prefix[i+1]=prefix[i]+1;
            }
            else{
                prefix[i+1]=prefix[i];
            }
        }

        for(auto it:queries){
            int l=it[0];
            int r=it[1];

            ans.push_back(prefix[r+1]-prefix[l]);
        }

        return ans;

    }
};