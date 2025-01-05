class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        int m=prerequisites.size();

        vector<int> indegree(n,0);
        vector<int> adj[n];

        for(auto it: prerequisites){
            int u=it[0];
            int v=it[1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();

            for(auto neighbour:adj[node]){
                indegree[neighbour]--;

                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }

        return ans.size()==n;
    }
};