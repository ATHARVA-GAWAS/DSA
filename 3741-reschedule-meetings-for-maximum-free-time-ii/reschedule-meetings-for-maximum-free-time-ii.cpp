class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        vector<int> gap(n+1,0);

        gap[0] = startTime[0];

        for(int i = 1;i < n;i++){
            gap[i]=startTime[i]-endTime[i-1];
        }

        gap[n]=eventTime-endTime[n-1];

        vector<int> largestright(gap.size(),0);

        for(int i=gap.size()-2;i>=0;i--){
            largestright[i]=max(largestright[i+1],gap[i+1]);
        }

        int ans=0, largestleft=0;

        for(int i=1;i<gap.size();i++){
            int curgap=endTime[i-1]-startTime[i-1];

            if(curgap<=max(largestleft,largestright[i])){
                ans=max(ans,gap[i-1]+gap[i]+curgap);
            }

            ans=max(ans,gap[i-1]+gap[i]);

            largestleft=max(largestleft,gap[i-1]);
        }

        return ans;
    }
};