class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();

        if(n1!=n2){
            return false;
        }

        if(s1==s2){
            return true;
        }

        vector<int> freq1(26,0),freq2(26,0);

        for(auto it:s1){
            freq1[it-'a']++;
        }

        for(auto it:s2){
            freq2[it-'a']++;
        }

        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]){
                return false;
            }
        }

        int different_letter=0;

        for(int i=0;i<n1;i++){
            if(s1[i]!=s2[i]){
                different_letter++;
            }
        }

        return different_letter==2;
    }
};