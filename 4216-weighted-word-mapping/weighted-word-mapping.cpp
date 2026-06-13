class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n=words.size();

        int m=weights.size();

        string ans;

        for(string &word:words){
            long long sum=0;

            for(char ch:word){
                sum+=weights[ch-'a'];
            }

            ans.push_back('z'-(sum%26));
        }

        return ans;
    }
};