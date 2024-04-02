class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> indS(200,0);
        vector<int> indT(200,0);

        int n=s.length();

        if(n!=t.length()){
            return false;
        }

        for(int i=0;i<n;i++){
            if(indS[s[i]]!=indT[t[i]]){
                return false;
            }

            indS[s[i]]=i+1;
            indT[t[i]]=i+1;
        }
        return true;
    }
};