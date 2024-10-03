class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        int m=prerequisites.size();

        vector<int> indegree(n,0);
        vector<int> adj[n];

        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
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

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        return ans.size()==n;
    }
};