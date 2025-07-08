class Solution {
    int f(vector<vector<int>>& events,int ind, int k,vector<vector<int>> &dp){
        int n=events.size();

        if(ind>=n || k==0){
            return 0;
        }

        if(dp[ind][k]!=-1){
            return dp[ind][k];
        }

        int start=events[ind][0];
        int end=events[ind][1];
        int val=events[ind][2];

        int nottake=f(events,ind+1,k,dp);

        int j;

        for(j=ind+1;j<n;j++){
            if(events[j][0]>events[ind][1]){
                break;
            }
        }

        int take=val+f(events,j,k-1,dp);

        return dp[ind][k]=max(nottake,take);
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();

        sort(events.begin(),events.end());

        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));

        return f(events,0,k,dp);
    }
};