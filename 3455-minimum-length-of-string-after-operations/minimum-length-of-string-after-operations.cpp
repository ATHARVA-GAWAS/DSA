class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();

        vector<int> freq(26,0);

        for(auto it:s){
            freq[it-'a']++;
        }

        for(int i=0;i<26;i++){
            if(freq[i]<3){
                continue;
            }
            else if(freq[i]%2==0){
                freq[i]=2;
            }
            else if(freq[i]%2!=0){
                freq[i]=1;
            }
        }

        int len=0;

        for(int i=0;i<26;i++){
            len+=freq[i];
        }

        return len;
    }
};