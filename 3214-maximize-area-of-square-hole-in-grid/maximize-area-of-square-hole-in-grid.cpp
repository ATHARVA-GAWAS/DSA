class Solution {
    int maxlen(vector<int>&bars){
        int cnt=2,len=2;

        for(int i=1;i<bars.size();i++){
            if(bars[i]==bars[i-1]+1){
                cnt++;
            }
            else{
                cnt=2;
            }

            len=max(len,cnt);
        }

        return len;
    }
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int side=min(maxlen(hBars),maxlen(vBars));

        return side*side;
    }
};