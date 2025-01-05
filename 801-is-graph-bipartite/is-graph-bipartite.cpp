class Solution {
private:
    bool isSameColored(int node,int color,vector<int> &vis,vector<vector<int>> &graph){
        vis[node]=color;

        //neighbours
        for(auto neighbour:graph[node]){
            if(vis[neighbour]==-1){
                if(isSameColored(neighbour,!color,vis,graph)==false){
                    return false;
                }
            }
            else if(vis[neighbour]==color){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n=graph.size();
        
        vector<int> vis(n,-1);

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