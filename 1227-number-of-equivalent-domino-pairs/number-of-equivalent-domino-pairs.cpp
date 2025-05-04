class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n=dominoes.size();
        int m=dominoes[0].size();

        unordered_map<int, int> mp;

        int res = 0;

        for (auto& d : dominoes) {
            int a = d[0], b = d[1];

            // normalize: always smaller first
            int key;
            
            if(a < b){
                key=a * 10 + b;
            }
            else{
                key=b * 10 + a;
            }

            res+=mp[key]++;
        }

        return res;
    }
};