class Solution {
    bool checkSubArray(int i,int j,int k,vector<vector<int>>& grid){
        int target=0;

        for(int col=j;col<j+k;col++){
            target+=grid[i][col];
        }

        for(int r=i;r<i+k;r++){
            int rowsum=0;

            for(int c=j;c<j+k;c++){
                rowsum+=grid[r][c];
            }

            if(rowsum!=target){
                return false;
            }
        }

        for(int c=j;c<j+k;c++){
            int colsum=0;

            for(int r=i;r<i+k;r++){
                colsum+=grid[r][c];
            }

            if(colsum!=target){
                return false;
            }
        }

        int diag1=0,diag2=0;

        for(int d=0;d<k;d++){
            diag1+=grid[i+d][j+d];

            diag2+=grid[i+d][j+k-d-1];
        }

        return diag1==target && diag2==target;
    }
    bool isSquare(int k,vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i+k<=n;i++){
            for(int j=0;j+k<=m;j++){
                if(checkSubArray(i,j,k,grid)){
                    return true;
                }
            }
        }

        return false;
    }
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int maxsize=min(n,m);

        for(int k=maxsize;k>=2;k--){
            if(isSquare(k,grid)){
                return k;
            }
        }

        return 1;
    }
};