class Solution {
    long long f(int robopos,int factpos, vector<int> &fact,vector<int>&robot,vector<vector<long long>> &dp){
        if(robopos<0){
            return 0;
        }
        if(factpos<0){
            return LONG_MAX/10;
        }

        if(dp[robopos][factpos]!=-1){
            return dp[robopos][factpos];
        }

        long long pick=abs(robot[robopos]-fact[factpos])+f(robopos-1,factpos-1,fact,robot,dp);

        long long notpick=f(robopos,factpos-1,fact,robot,dp);

        return dp[robopos][factpos]=min(pick,notpick);
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n=robot.size();
        
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());

        vector<int> fact;

        for(auto it:factory){
            int pos=it[0];
            int limit=it[1];

            for(int i=0;i<limit;i++){
                fact.push_back(pos);
            }
        }

        int m=fact.size();

        vector<vector<long long>> dp(n+1,vector<long long>(m+1,-1));

        return f(n-1,m-1,fact,robot,dp);
    }
};