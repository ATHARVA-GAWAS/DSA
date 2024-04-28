class Solution {
public:
    void dfs1(int i, int p, vector<int>& ans, vector<int>& join, vector<int>adj[]){
        for(auto it: adj[i]){
            if(p!=it){
                dfs1(it, i, ans, join, adj);
                join[i]+=join[it];
                ans[i]+=ans[it]+join[it];
            }
        }
    }
    void dfs2(int i, int p, vector<int>& ans, vector<int>& join, vector<int>adj[]){
        for(auto it: adj[i]){
            if(p!=it){
                ans[it]+=ans[i]+join[0]-join[it]-ans[it]-join[it];
                dfs2(it, i, ans, join, adj);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>ans(n, 0), join(n, 1);
        vector<int>adj[n];
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs1(0, -1, ans, join, adj);
        dfs2(0, -1, ans, join, adj);
        return ans;
    }
};