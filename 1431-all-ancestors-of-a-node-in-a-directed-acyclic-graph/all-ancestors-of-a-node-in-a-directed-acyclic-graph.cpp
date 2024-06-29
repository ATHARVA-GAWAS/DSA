class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>(0));
        vector<int> indegree(n);
        for(auto& it : edges) { //build adjecent list graph
            graph[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<unordered_set<int>> ancestors(n);
        while(q.size() > 0) {
            int node = q.front(); 
            q.pop();
            for(int it : graph[node]) {
                indegree[it]--;
                ancestors[it].insert(node);
                for(int ancestor : ancestors[node]) {
                    ancestors[it].insert(ancestor);
                }
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        vector<vector<int>> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
            sort(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};