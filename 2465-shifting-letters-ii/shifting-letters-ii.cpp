class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> prefix_diff(n+1,0);

        for(auto& sh : shifts){
            int start = sh[0] , end = sh[1] , dir = sh[2];

            prefix_diff[start] += (dir == 1?1:-1);
            
            prefix_diff[end+1] -= (dir == 1?1:-1);
        }

        int currentshift = 0;
        for(int i=0;i<n;i++){
            currentshift += prefix_diff[i];
            prefix_diff[i] = currentshift;
        }

        for(int i=0;i<n;i++){

            int netsht = (prefix_diff[i]%26+26)%26;

            s[i] = 'a' + (s[i] - 'a' + netsht)%26;
        }

        return s;
    }
};