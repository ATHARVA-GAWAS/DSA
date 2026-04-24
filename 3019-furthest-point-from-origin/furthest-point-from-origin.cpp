class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.size();

        int cnt=0;

        int res=0;

        int cntL=0,cntR=0,cnt_=0;

        for(int i=0;i<n;i++){
            cntL+=(moves[i]=='L');
            cntR+=(moves[i]=='R');
            cnt_+=(moves[i]=='_');
        }

        if(cntL>cntR){
            res=cntL-cntR;
        }
        else{
            res=cntR-cntL;
        }

        return res+cnt_;
    }
};