class Solution {
    int binarysearch(vector<vector<int>>&events,int endtime){
        int n=events.size();
        int l=0,r=n-1;
        int res=n;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(events[mid][0]>endtime){
                res=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return res;
    }
    int f(vector<vector<int>>&events,int ind,int cnt,vector<vector<int>> &dp){
        int n=events.size();

        if(dp[ind][cnt]!=-1){
            return dp[ind][cnt];
        }

        if(cnt==2 || ind>=n){
            return 0;
        }

        int nextValidEventIndex=binarysearch(events,events[ind][1]);

        int take=events[ind][2]+f(events,nextValidEventIndex,cnt+1,dp);
        int nottake=f(events,ind+1,cnt,dp);

        return dp[ind][cnt]=max(take,nottake);
    }
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        int cnt = 0;

        vector<vector<int>> dp(n+1,vector<int>(3,-1));

        sort(events.begin(),events.end());

        return f(events,0,cnt,dp);
    }
};