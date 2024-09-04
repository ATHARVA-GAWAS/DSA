class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
       
        map<vector<int>,int> mp;

        for(auto it:obstacles){
            mp[it]++;
        }
        int ans=0;
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int x=0,y=0,k=0;

        for(auto it:commands){
            if(it==-1){
                k=(k+1)%4;
            }
            else if(it==-2){
                k=(k-1+4)%4;
            }

            else{
                for(int j=0;j<it;j++){
                    int newx=x+dir[k][0];
                    int newy=y+dir[k][1];

                    if(mp.count({newx,newy})){
                        break;
                    }

                    else{
                        x=newx;
                        y=newy;
                        ans=max(ans,x*x+y*y);
                    }
                }
            }
        }
        return ans;
    }
};