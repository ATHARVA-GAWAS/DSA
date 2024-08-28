class Solution {
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j){
        if(i < 0 || i >= grid1.size() || j < 0 || j >= grid1[0].size()) {
            return true;
        }
        
        if(grid2[i][j] != 1) { //we only need land
            return true;
        }
        grid2[i][j] = -1; //mark visited
  
        bool result = (grid1[i][j] == 1); //grid1[i][j] must have 1

        result = result & dfs(grid1, grid2, i+1, j); //Down
        result = result & dfs(grid1, grid2, i-1, j); //Up
        result = result & dfs(grid1, grid2, i, j+1);  //Right
        result = result & dfs(grid1, grid2, i, j-1); //Left

        return result;

    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans=0;

        int n=grid2.size();
        int m=grid2[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 && dfs(grid1,grid2,i,j )){
                    ans++;
                }
            }
        }
        return ans;
    }
};