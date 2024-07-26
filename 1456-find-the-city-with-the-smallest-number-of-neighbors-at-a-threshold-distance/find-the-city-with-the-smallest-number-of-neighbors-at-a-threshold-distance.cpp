class Solution {
public:
    #define P pair<int,int>
    void dijkstra(int n,unordered_map<int,vector<P>>&adj,vector<int>&result,int source){
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0,source});
        fill(result.begin(), result.end(), INT_MAX);
        result[source]=0;

        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto&p :adj[node]){
                int adjNode=p.first;
                int dist=p.second;

                if(d+dist < result[adjNode]){
                    result[adjNode]=d+dist;
                    pq.push({d+dist,adjNode});
                }
            }
        }
    }

    int getCityWithFewestReachable(int n,const vector<vector<int>>& shortestPathMatrix, int distanceThreshold){
        int cityWithFewestReachable = -1;
        int fewestReachableCount = INT_MAX;

        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && shortestPathMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }

            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,vector<P>> adj;

        vector<vector<int>> shortestPathMatrix(n,vector<int>(n,INT_MAX));

        for(int i=0;i<n;i++){
            shortestPathMatrix[i][i]=0;
        }

        for(auto it:edges){
            int start=it[0],end=it[1],wt=it[2];

            adj[start].push_back({end,wt});
            adj[end].push_back({start,wt});

        }

        for(int i=0;i<n;i++){
            dijkstra(n,adj,shortestPathMatrix[i],i);
        }

        return getCityWithFewestReachable(n,shortestPathMatrix,distanceThreshold);
    }
};