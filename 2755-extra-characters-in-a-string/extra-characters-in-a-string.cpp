class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,bool> mp;
        int n=s.size();
        vector<int> dp(s.size()+1,0);
        for(auto&word :dictionary){
            mp[word]=true;
        }
        for(int ind=n-1;ind>=0;ind--){
            string curr="";
            int res=s.size();
            for(int i=ind;i<s.size();i++){
                curr.push_back(s[i]);
                int extra=curr.size();
                if(mp[curr]){
                    extra=0;
                }
                extra+=dp[i+1];
                res=min(res,extra);
            }
             dp[ind]=res;
        }
        return dp[0];
        
    }
};