class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i = 0, j = 0, ans = 0;
        unordered_map<char, int> m;

        while (j < n) {
            m[s[j]]++; 

            while (m['a'] > 0 && m['b'] > 0 && m['c'] > 0) {
              
                ans += (n - j);

                m[s[i]]--; 
                i++;
            }
            j++; 
        }

        return ans;
    }
};