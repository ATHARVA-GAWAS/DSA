class Solution {
public:
    bool solve(vector<int>& stones, int index, int jumpSize,vector<vector<int>> &dp) 
    {
        if (index == stones.size() - 1) {
            return true;
        }
        if(dp[index][jumpSize]!=-1)
        return dp[index][jumpSize];
        for (int i = index + 1; i < stones.size(); ++i) 
        {
            int gap = stones[i] - stones[index];
            if (gap >= jumpSize - 1 && gap <= jumpSize + 1) 
            {
                if (solve(stones, i, gap,dp)) {
                    return dp[index][jumpSize]=true;  
                }
            }
        }

        return dp[index][jumpSize]= false; 
    }
    bool canCross(vector<int>& stones) {
        vector<vector<int>> dp(stones.size()+1,vector<int> (stones.size()+1,-1));
        return solve(stones, 0, 0 ,dp);
    }

};