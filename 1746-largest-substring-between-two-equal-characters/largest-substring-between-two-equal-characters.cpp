class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        int maxdiff=-1;
        for(int i=0;i<n;i++){
            int diff=0;
            char ch=s[i];
            if(mp.find(ch)==mp.end()){
                mp[ch]=i;
            }
            else{
                diff= i-mp[ch]-1;
                maxdiff=max(maxdiff,diff);
            }
            
        }
        return maxdiff;
    }
};
// tc: O(N)  sc= O(26)