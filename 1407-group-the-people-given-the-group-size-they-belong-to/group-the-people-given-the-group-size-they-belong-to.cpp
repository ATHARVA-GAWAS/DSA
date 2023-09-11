class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        map<int,vector<int>> mp;
        for(int i=0;i<groupSizes.size();i++){
            mp[groupSizes[i]].push_back(i);
        }
        for(auto it:mp){
            int s=it.first;
            
            vector<int> r;
            for(auto i:it.second){
                if(r.size()==s){
                    
                    ans.push_back(r);
                    r.clear();
                }
                r.push_back(i);
            }
            ans.push_back(r);

        }
        return ans;
    }
};