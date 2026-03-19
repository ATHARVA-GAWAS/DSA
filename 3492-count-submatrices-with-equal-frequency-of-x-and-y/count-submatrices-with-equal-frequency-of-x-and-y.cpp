class Solution {
    vector<vector<int>> prefsum(vector<vector<char>>& grid,char targetchar){
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> prefsum(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                prefsum[i][j]=(grid[i][j]==targetchar);

                if(i>0){
                    prefsum[i][j]+=prefsum[i-1][j];
                }

                if(j>0){
                    prefsum[i][j]+=prefsum[i][j-1];
                }

                if(i>0 && j>0){
                    prefsum[i][j]-=prefsum[i-1][j-1];
                }
            }
        }

        return prefsum;
    }
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> xcountprefsum=prefsum(grid,'X');

        vector<vector<int>> ycountprefsum=prefsum(grid,'Y');

        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(xcountprefsum[i][j]==ycountprefsum[i][j] && xcountprefsum[i][j]>0){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};