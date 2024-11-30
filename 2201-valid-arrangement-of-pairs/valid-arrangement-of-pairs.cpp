class Solution {
    void dfs(int node, vector<int>&eulerpath,unordered_map<int,vector<int>> &adj){
        while(!adj[node].empty()){
            int nextnode=adj[node].back();
            adj[node].pop_back();
            dfs(nextnode,eulerpath,adj);  // Remove the edge after visiting
        }
        eulerpath.push_back(node);
    }
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> adj;

        unordered_map<int,int> indegree,outdegree;

        for(auto &edge: pairs){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);  //u --> v
            outdegree[u]++;
            indegree[v]++;
        }

        int startnode=pairs[0][0];

        for(auto &it:adj){
            int node=it.first;

            if(outdegree[node]-indegree[node]==1){
                startnode=node;
                break;
            }
        }

        vector<int> eulerpath;

        dfs(startnode,eulerpath,adj);

        reverse(eulerpath.begin(),eulerpath.end());

        vector<vector<int>> res;

        for(int i=0;i<eulerpath.size()-1;i++){
            res.push_back({eulerpath[i],eulerpath[i+1]});
        }

        return res;
    }
};