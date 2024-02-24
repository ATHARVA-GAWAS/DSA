class Solution {
public:
    using pii=pair<int,int>;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pii>> graph(n);
        for(auto &e:meetings){
            int u=e[0],v=e[1],w=e[2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        vector<bool> visited(n);
        priority_queue<pii,vector<pii>,greater<>> pq;
        pq.push({0,0});
        pq.push({0,firstPerson});
        while(pq.size()){
            auto [t,u]=pq.top();
            pq.pop();
            if(visited[u])
                continue;
            visited[u]=1;
            for(auto [v,w]:graph[u]){
                if(!visited[v] and t<=w)
                    pq.push({w,v});
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(visited[i])
                ans.push_back(i);
        }
        return ans;
    }
};