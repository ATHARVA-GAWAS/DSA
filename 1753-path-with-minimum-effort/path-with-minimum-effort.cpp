class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        vector<vector<int>> dist(n,vector<int>(m,1e9));

        dist[0][0]=0;

        pq.push({0,{0,0}});

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        while(!pq.empty()){
            int diff=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();

            if(r==n-1 && c==m-1){
                return diff;
            }

            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int neweffort=max(abs(heights[r][c]-heights[nrow][ncol]),diff);

                    if(neweffort< dist[nrow][ncol]){
                        dist[nrow][ncol]=neweffort;
                        pq.push({neweffort,{nrow,ncol}});
                    }
                }
            }
        }

        return 0;
    }
};