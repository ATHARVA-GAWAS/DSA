class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0,rsum=0,maxsum=0;
        int n=cardPoints.size();

        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
            maxsum=lsum;
        }

        int r=n-1;

        for(int l=k-1;l>=0;l--){
            lsum=lsum-cardPoints[l];
            rsum+=cardPoints[r];
            r--;
            maxsum=max(maxsum,lsum+rsum);
        }
        return maxsum;
    }
};