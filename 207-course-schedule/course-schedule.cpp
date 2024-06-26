class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int m=prerequisites.size();
        int n=numCourses;
        vector<int> indegree(n,0);
        vector<int> adj[n];

        for(int i=0;i<m;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
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

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        if(ans.size()==n){
            return true;
        }
        return false;
    }
};