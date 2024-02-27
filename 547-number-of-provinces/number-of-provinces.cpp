class Solution {
    void dfs(int ind,vector<int> &vis,vector<vector<int>>& isConnected){
        vis[ind]=1;
        for(int i=0;i<isConnected.size();i++){
            if(ind!=i && vis[i]==0 && isConnected[i][ind]==1){
                dfs(i,vis,isConnected);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i,vis,isConnected);
            }
        }
        return cnt;
    }
};