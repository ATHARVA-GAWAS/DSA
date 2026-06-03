class Solution {
    int quick(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd)
    {
        int mini = INT_MAX;
        
        for(int i=0;i<ls.size();i++)
        {
            mini = min(mini,ls[i]+ld[i]);
        }

        int ans = INT_MAX;

        for(int i=0;i<ws.size();i++)
        {
            ans = min(ans,max(mini,ws[i])+wd[i]);
        }

        return ans;
    }
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int a=quick(landStartTime,landDuration,waterStartTime,waterDuration);
        int b=quick(waterStartTime,waterDuration,landStartTime,landDuration);

        return min(a,b);
    }
};