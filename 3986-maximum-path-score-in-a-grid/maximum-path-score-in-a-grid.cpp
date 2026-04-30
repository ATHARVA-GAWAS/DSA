class Solution {
public:
    vector<vector<vector<int>>>dp;
    int m, n;

    int find(int i, int j, int k, vector<vector<int>>& grid) {
        if (i >= m || j >= n)
            return INT_MIN;

        if (i == m - 1 && j == n - 1) {
            if (grid[i][j] == 0)
                return 0;

            if (k == 0)
                return INT_MIN;

            return grid[i][j];
        }

        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        int res = INT_MIN, cost = grid[i][j] > 0;

        if (cost <= k) {
            int c1 = find(i + 1, j, k - cost, grid);
            int c2 = find(i, j + 1, k - cost, grid);
            
            if (c1 != INT_MIN)
                res = max(res, grid[i][j] + c1);

            if (c2 != INT_MIN)
                res = max(res, grid[i][j] + c2);
        }
        return dp[i][j][k] = res;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        k = min(k, m+n-1);

        dp.resize(m,vector<vector<int>>(n,vector<int>(k+1,-1)));

        return max(find(0, 0, k, grid), -1);
    }
};