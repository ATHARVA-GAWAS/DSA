class Solution {
    bool dfs(int node,int dest,vector<int> adj[],vector<int>&vis){
        vis[node]=1;

        if(node==dest){
            return true;
        }

        for(auto neighbour: adj[node]){

            if(!vis[neighbour]){
                if (dfs(neighbour,dest,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       vector<int> adj[n];
       for(auto edge: edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
       } 
       vector<int> vis(n,0);

       return dfs(source,destination,adj,vis);
    }
};