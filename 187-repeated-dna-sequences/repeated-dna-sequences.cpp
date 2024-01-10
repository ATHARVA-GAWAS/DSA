class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        vector<string> ans;
        if(n<10){
            return {};
        }
        unordered_map<string,int> mp;
        for(int i=0;i<s.size()-9;i++){
            string str=s.substr(i,10);
            mp[str]++;
        }

        for(auto it: mp){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }
        return ans;
        
    }
};