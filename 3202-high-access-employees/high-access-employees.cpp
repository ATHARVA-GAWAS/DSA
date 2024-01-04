class Solution {
    bool solve(vector<int> times){
       for(int i=0;i<times.size()-2;i++){
           if(times[i+2]-times[i]<60){
               return true;
           }
       }
       return false;
    }
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        int n=access_times.size();
        int m=access_times[0].size();
        unordered_map<string,vector<int>> mp;
        vector<string> ans;
        for(auto it: access_times){
            string hr=it[1].substr(0,2);
            string min=it[1].substr(2,2);
            int totalmin=stoi(hr)*60+stoi(min);
            mp[it[0]].push_back(totalmin);
        }
        for(auto x:mp){
            if(x.second.size()<3){
                continue;
            }
            sort(x.second.begin(),x.second.end());
            if(solve(x.second)){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};