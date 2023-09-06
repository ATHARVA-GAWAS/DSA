class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
         vector<int> prev(n+1,0),cur(m+1,0);
         for(int i=0; i<n ;i++){
         for(int j=0; j<m; j++){
          
          //base conditions
          if(i>=0 && j>=0 && obstacleGrid[i][j]==1){
            cur[j]=0;
            continue;
          }
          if(i==0 && j==0){
              cur[j]=1;
              continue;
          }
          
          int up=0;
          int left = 0;
          
          if(i>0) 
            up = prev[j];
          if(j>0)
            left = cur[j-1];
            
          cur[j] = up+left;
      }
      prev=cur;
     }
  
  return prev[m-1];
    }
};