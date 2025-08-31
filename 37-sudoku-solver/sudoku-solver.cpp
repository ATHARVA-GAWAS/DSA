class Solution {
    bool is_valid(vector<vector<char>>& board, int row, int col, char ch){
        for(int i=0;i<9;i++){
            if(board[i][col]==ch){      //check column
                return false;
            }
            if(board[row][i]==ch){      //check row
                return false;
            }

            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch){   // Check 3x3 subgrid
                return false;
            }
        }

        return true;
    }
    bool f(vector<vector<char>> &board){
        for(int i=0;i<9;i++){
            for(int j=0;j<=9;j++){
                if(board[i][j]!='.'){
                    continue;
                }

                for(char ch='1';ch<='9';ch++){
                    if(is_valid(board,i,j,ch)){
                        board[i][j]=ch;

                        if(f(board)){
                            return true;
                        }

                        board[i][j]='.';
                    }
                }

                return false;
            }
        }

        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        f(board);
    }
};