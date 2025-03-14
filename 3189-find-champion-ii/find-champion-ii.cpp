class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges){
        vector<int> indegree(n,0);

        for(auto it:edges){
            int u=it[0];
            int v=it[1];

            indegree[v]++;
        }        

        int champ=-1;
        int cnt=0;

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                cnt++;
                champ=i;

                if(cnt>1){
                    return -1;
                }
            }
        }

        return champ;
    }
};