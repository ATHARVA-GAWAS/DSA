class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>> adj[n+1];

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int> dist(n+1,1e9);

        dist[k]=0;
        pq.push({0,k});

        
        while(!pq.empty()){
            int node=pq.top().second;
            int distance=pq.top().first;
            pq.pop();

            for(auto x:adj[node]){
                int adjnode=x.first;
                int adjdist=x.second;

                if(distance+adjdist < dist[adjnode]){
                    dist[adjnode]=distance+adjdist;
                    pq.push({adjdist+distance, adjnode});
                }
            }
        }

        int ans=-1;

        for(int i=1;i<=n;i++){
            ans=max(ans,dist[i]);
        }

        if(ans==1e9){
            return -1;
        }

        return ans;
    }
};