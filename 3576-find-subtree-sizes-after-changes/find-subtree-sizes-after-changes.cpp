class Solution {
    vector <vector <int>> adj;
    vector <stack<int>> letterNodes;

    void dfs(int node,vector <int>&ans){
        ans[node] = 1;
        
        for(auto it:adj[node]){
            dfs(it,ans);
            ans[node] += ans[it];
        }
    }

    void dfs1(int node,string &s,vector <int> &yVal){
        if(letterNodes[s[node]-'a'].size() > 0){
            yVal[node] = letterNodes[s[node] - 'a'].top();
        }

        letterNodes[s[node] - 'a'].push(node);

        for(auto it:adj[node]){
            dfs1(it,s,yVal);
        }

        letterNodes[s[node] - 'a'].pop();
    }

public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = s.size();

        vector <int> yVal(n,-1);
        adj.resize(n);

        for(int i = 1;i < n;i++){
            adj[parent[i]].push_back(i);
        }

        letterNodes.resize(26);

        dfs1(0,s,yVal);
        adj.clear();
        adj.resize(n);
        for(int i = 1;i < n;i++){
            if(yVal[i] != -1) parent[i] = yVal[i];
            adj[parent[i]].push_back(i);
        }
        
        vector <int> ans(n);
        dfs(0,ans);
        return ans;
    }
};