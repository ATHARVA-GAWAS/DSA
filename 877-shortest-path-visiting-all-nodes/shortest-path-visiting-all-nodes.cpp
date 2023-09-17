class Solution {
public:
    int dfs(int u,vector<vector<int>> &dist,int mask,vector<vector<int>> &dp){
        if(mask==0){
            return 0;
        }
        if(dp[u][mask]!=-1){
            return dp[u][mask];
        }
        
        int n =dist.size();
        int ans=9999999;
        
        for(int i=0;i<n;i++){
            int r = 1<<i & mask;
            if(r){
                int path=dfs(i,dist,mask^(1<<i),dp)+dist[u][i];
                ans=min(path,ans);
            }
        }
        
        return dp[u][mask]=ans;
        
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        
        vector<vector<int>> dist(graph.size(),vector<int>(graph.size(),9999999));
        
        int n=graph.size();
        int maskSize=1<<n;
        
        vector<vector<int>> dp(n,vector<int>(maskSize,-1));
        
        for(int i=0;i<graph.size();i++){
            dist[i][i]=0;
            for(int j=0;j<graph[i].size();j++){
                dist[i][graph[i][j]]=1;
            }    
        }
        
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][j]>dist[i][k]+dist[k][j]){
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }
        
        int ans=9999999;
        for(int i=0;i<n;i++){
            int mask=(1<<n) -1;
            int shortestPath=dfs(i,dist,mask^(1<<i),dp);
            ans=min(ans,shortestPath);
        }
        
        return ans;
            
    }
};
