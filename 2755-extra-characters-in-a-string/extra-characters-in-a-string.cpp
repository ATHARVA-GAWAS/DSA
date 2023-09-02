class Solution {
    int f(int ind,string s,unordered_map<string,bool>&mp,vector<int> &dp){
        if(ind>=s.size()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        string curr="";
        int res=s.size();
        for(int i=ind;i<s.size();i++){
            curr.push_back(s[i]);
            int extra=curr.size();
            if(mp[curr]){
                extra=0;
            }
            extra+=f(i+1,s,mp,dp);
            res=min(res,extra);
        }
        return dp[ind]=res;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,bool> mp;
        vector<int> dp(s.size(),-1);
        for(auto&word :dictionary){
            mp[word]=true;
        }
        return f(0,s,mp,dp);
        
    }
};