class Solution {
bool dfs(int node, vector<int>& vis,vector<int>& pathvis, vector<vector<int>>& graph,vector<int>&check ){
    vis[node]=1;
    pathvis[node]=1;
   
    for(auto it: graph[node] ){
        if(!vis[it]){
            if(dfs(it,vis,pathvis,graph,check)==true){
                check[node]=0;
                 return true;
            }
        }
        else if(pathvis[it]){
                check[node]=0;
                return true;
            }
            
    }
    check[node]=1;
    pathvis[node]=0;
    return false;
}
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        
         
         vector<int> adjRev[n];
          vector<int> indegree(n,0);

        //create reversed adjacency list
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        //push terminal nodes in the queue
        queue<int> q;
        vector<int> safenodes;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        //BFS
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safenodes.push_back(node);
            for(auto it: adjRev[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
            
        }
        sort(safenodes.begin(),safenodes.end());
        return safenodes;
    }
};