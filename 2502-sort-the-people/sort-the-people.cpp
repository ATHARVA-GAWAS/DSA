class Solution {
    bool static cmp(pair<string,int>&a,pair<string,int>&b){
        return a.second>b.second;
    }
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string,int>> arr;

        for(int i=0;i<names.size();i++){
            arr.push_back(make_pair(names[i],heights[i]));
        }

        sort(arr.begin(),arr.end(),cmp);
        vector<string> ans;

        for(auto it: arr){
            ans.push_back(it.first);
        }
        return ans;
    }
};