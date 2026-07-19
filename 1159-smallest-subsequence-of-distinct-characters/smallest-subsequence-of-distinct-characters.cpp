class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();

        vector<int> freq(26,0);

        vector<int> seen(26,0);

        for(auto it:s){
            freq[it-'a']++;
        }

        string res="";

        for(auto it:s){
            freq[it-'a']--;

            if(seen[it-'a']){
                continue;
            }

            while(!res.empty() && res.back() > it && freq[res.back()-'a']>0){
                seen[res.back()-'a']=false;

                res.pop_back();
            }

            res+=it;

            seen[it-'a']=true;
        }

        return res;
    }
};