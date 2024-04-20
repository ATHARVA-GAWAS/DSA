class Solution {
public:

    void dfs(vector<vector<int>>& land, int row, int col, vector<int> &temp){
        //base case
        if(row<0 || row >= land.size() || col<0 || col >= land[0].size() || land[row][col]==0) return;

        //making as visited
        land[row][col]=0;

        //making bottom right
        temp[2]=max(temp[2],row);
        temp[3]=max(temp[3],col);

        dfs(land, row-1, col, temp); //go up
        dfs(land, row+1, col, temp); //go down
        dfs(land, row, col-1, temp); //go left
        dfs(land, row, col+1, temp); //go right
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        //disconnected components
        vector<vector<int>> ans;
        for(int i=0; i<land.size(); i++){
            for(int j=0; j<land[0].size(); j++){
                if(land[i][j]==1){
                    vector<int> temp(4,0);
                    //making top left
                    temp[0]=i;
                    temp[1]=j;
                    
                    dfs(land, i, j, temp);
                    ans.push_back(temp);
                }
            }
        }

        return ans;
    }
};