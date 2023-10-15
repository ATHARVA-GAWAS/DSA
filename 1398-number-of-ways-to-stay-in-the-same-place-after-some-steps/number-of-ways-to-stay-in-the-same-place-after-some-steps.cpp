class Solution {
public:
    int solve(int pos, int steps, int n, vector<vector<int>>&dp)
    {
        if(pos==0 && steps==0) //base case 1 . see above
            return 1;
        else if(pos>=n || pos<0 || pos-steps>0) // base case 2.
            return 0;
        else if(steps==0) //base case 3.
            return 0;
        if(dp[pos][steps]!=-1)
            return dp[pos][steps];
        int a = solve(pos+1, steps-1, n, dp); // 1 step forward
        int b = solve(pos, steps-1, n, dp); // no movement
        int c = solve(pos-1, steps-1, n, dp); // 1 step backward
        return dp[pos][steps] = (0LL+a+b+c)%1000000007; // sum of all possibilities
    }
    int numWays(int steps, int arrLen) {
        vector<vector<int>>dp(steps+1, vector<int>(steps+1, -1));
        return solve(0, steps, arrLen, dp);
    }
};