class Solution {
    bool dfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>>& board, int k, string word){
        int n=board.size();
        int m=board[0].size();

        if (k == word.size()) return true;

        if(i<0 || j<0 || i>=n || j>=m || vis[i][j]==1){
            return false;
        }

        if(board[i][j]!=word[k]){
            return false;
        }

        vis[i][j]=1;

        bool a=dfs(i-1,j,vis,board,k+1,word);
        bool b=dfs(i,j-1,vis,board,k+1,word);
        bool c=dfs(i+1,j,vis,board,k+1,word);
        bool d=dfs(i,j+1,vis,board,k+1,word);

        vis[i][j]=0;

        return a||b||c||d;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,-1));

        bool ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=dfs(i,j,vis,board,0,word);
                if(ans==true){
                    return true;
                }
            }
        }

        return false;
    }
};