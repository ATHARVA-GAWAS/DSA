class Solution {
    static bool cmp(pair<char,int> &a,pair<char,int> &b){
        if(a.second==b.second){
            return a.first<b.second;
        }
        return a.second>b.second;
    }
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        vector<pair<char,int>> v;
        priority_queue <int, vector<int>, greater<int>> gq;
        for(auto it:s){
            mp[it]++;
        }
        for(auto it:mp){
            v.push_back(it);
        }
        sort(v.begin(),v.end(),cmp);
        string str="";
        for(auto it:v){
            int x=it.second;
            while(x--){
               str+=it.first;
            }
            
        }
        return str;
    }
};