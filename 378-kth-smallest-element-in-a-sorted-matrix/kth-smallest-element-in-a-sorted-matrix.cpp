class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;

        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pq.push(matrix[i][j]);
            }
        }

        int ans;

        while(k--){
            ans=pq.top();
            pq.pop();
        }

        return ans;
    }
};