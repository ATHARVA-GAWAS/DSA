class Solution {
private:
    bool isSameColored(int node,int color,vector<int> &vis,vector<vector<int>> &graph){
        vis[node]=color;
        //neighbours
        for(auto it:graph[node]){
            if(vis[it]==-1){
                if(isSameColored(it,!color,vis,graph)==false){
                    return false;
                }
            }
            else if(vis[it]==color){
                return false;
            }
        }
        return true;
        
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //graph is the adj list
        int n=graph.size();
        vector<int> vis(n,-1);
        //multisource as per point 4 in the graph properties
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(isSameColored(i,0,vis,graph)==false){
                    return false;
                }
            }
        }
        return  true;
        
        
    }
};