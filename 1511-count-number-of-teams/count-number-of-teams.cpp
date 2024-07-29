class Solution {
public:
    int numTeams(vector<int>& rating) {
        int count = 0;
        int n = rating.size();

        for(int k=1;k<n-1;k++){
            int cntSmallLeft=0,cntLargeLeft=0,cntSmallRight=0,cntLargeRight=0;

            for(int i=0;i<k;i++){
                if(rating[i]<rating[k]){
                    cntSmallLeft++;
                }
                else if(rating[i]>rating[k]){
                    cntLargeLeft++;
                }
            }

            for(int j=k+1;j<n;j++){
                if(rating[k]<rating[j]){
                    cntLargeRight++;
                }
                else if(rating[k]>rating[j]){
                    cntSmallRight++;
                }
            }
            count+=(cntLargeLeft*cntSmallRight)+(cntSmallLeft*cntLargeRight);
        }
        return count;
    }
};