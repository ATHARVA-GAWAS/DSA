class Solution {
    int n;

    pair<int,int> getcoord(int s){
        int row=n-1-(s-1)/n;
        int col=(s-1)%n;

        if((n%2==1 && row%2==1) || (n%2==0 && row%2==0)){
            col=n-1-col;
        }

        return make_pair(row, col);
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        n=board.size();

        int steps=0;

        queue<int> que;

        vector<vector<bool>> vis(n, vector<bool>(n, false));

        vis[n-1][0]=true;

        que.push(1);

        vector<bool> seen(n*n+1,false);

        while(!que.empty()){
            int N=que.size();

            while(N--){
                int x=que.front();
                que.pop();

                if(x==n*n){
                    return steps;
                }

                for(int k=1;k<=6;k++){
                    if(x+k>n*n){
                        break;
                    }

                    pair<int,int> coord=getcoord(x+k);

                    int r=coord.first;
                    int c=coord.second;

                    if(vis[r][c]==true){
                        continue;
                    }

                    vis[r][c]=true;

                    if(board[r][c]==-1){
                        que.push(k+x);
                    }
                    else{
                        que.push(board[r][c]);
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};