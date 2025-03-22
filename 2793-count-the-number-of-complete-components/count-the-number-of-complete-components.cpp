class Solution {
    void dfs(int i, unordered_map<int, vector<int>> &adj, vector<bool> &vis, int &v, int &e){
        vis[i]=true;
        v++;
        e+=adj[i].size();

        for(int &it:adj[i]){
            if(!vis[it]){
                dfs(it,adj,vis,v,e);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(auto it: edges){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int res=0;

        vector<bool> vis(n,false);

        for(int i=0;i<n;i++){
            if(vis[i]==true){
                continue;
            }

            int v=0;
            int e=0;

            dfs(i,adj,vis,v,e);

            if((v*(v-1))==e){
                res++;
            }
        }
        return res;
    }
};