class Solution {
    void dfs(int node, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited) {
        visited.insert(node);
        for (int neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, graph, visited);
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        unordered_map<int,vector<int>> graph;
        unordered_set<int> vis;

        for(int i=0;i<n;i++){
            for (int j = i + 1; j < stones.size(); j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int numComponents = 0;
        for (int i = 0; i < stones.size(); i++) {
            if (vis.find(i) == vis.end()) {
                numComponents++;
                dfs(i, graph, vis);
            }
        }
        return stones.size() - numComponents;
    }
};