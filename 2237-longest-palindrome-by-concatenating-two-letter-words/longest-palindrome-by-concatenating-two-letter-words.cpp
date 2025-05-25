class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n=words.size();

        unordered_map<string, int> mp;

        int res=0;

        for(string &word:words){
            string reversedword=word;

            swap(reversedword[0],reversedword[1]);

            if(mp[reversedword]>0){
                res+=4;
                mp[reversedword]--;
            }
            else{
                mp[word]++;
            }
        }

        //Check equal character words. Use only one
        for(auto &it:mp){
            string word=it.first;
            int cnt=it.second;

            if(word[0]==word[1] && cnt>0){
                res+=2;
                break;
            }
        }

        return res;
    }
};