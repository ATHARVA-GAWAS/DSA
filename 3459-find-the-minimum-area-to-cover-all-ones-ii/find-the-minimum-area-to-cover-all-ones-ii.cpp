

class Solution {

    // Helper: find min area rectangle covering all 1's inside subgrid
    int area(vector<vector<int>>& grid, int row_start, int row_end, int col_start, int col_end) {
        int mini_row = 1e9;
        int maxi_row = -1e9;

        int mini_col = 1e9;
        int  maxi_col = -1e9;

        for (int i = row_start; i <= row_end; i++) {
            for (int j = col_start; j <= col_end; j++) {
                if (grid[i][j] == 1) {
                    mini_row = min(mini_row, i);
                    maxi_row = max(maxi_row, i);
                    mini_col = min(mini_col, j);
                    maxi_col = max(maxi_col, j);
                }
            }
        }

        if (mini_row == 1e9){
             return 0; 
             }

        int h = maxi_row - mini_row + 1;
        int w = maxi_col - mini_col + 1;
        return h * w;
    }

public:
    int minimumSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = INT_MAX;

        // -------- Partition 1: First cut row, then split bottom part into 2 columns --------
        for (int i = 0; i < n; i++) {
            int first = area(grid, 0, i, 0, m - 1);
            for (int j = 0; j < m; j++) {
                int second = area(grid, i + 1, n - 1, 0, j);
                int third  = area(grid, i + 1, n - 1, j + 1, m - 1);
                ans = min(ans, first + second + third);
            }
        }

        // -------- Partition 2: First cut row from bottom, then split top part into 2 columns --------
        for (int i = n - 1; i >= 0; i--) {
            int first = area(grid, i, n - 1, 0, m - 1);
            for (int j = 0; j < m; j++) {
                int second = area(grid, 0, i - 1, 0, j);
                int third  = area(grid, 0, i - 1, j + 1, m - 1);
                ans = min(ans, first + second + third);
            }
        }

        // -------- Partition 3: First cut column, then split right part into 2 rows --------
        for (int j = 0; j < m; j++) {
            int first = area(grid, 0, n - 1, 0, j);
            for (int i = 0; i < n; i++) {
                int second = area(grid, 0, i, j + 1, m - 1);
                int third  = area(grid, i + 1, n - 1, j + 1, m - 1);
                ans = min(ans, first + second + third);
            }
        }

        // -------- Partition 4: First cut column from right, then split left part into 2 rows --------
        for (int j = m - 1; j >= 0; j--) {
            int first = area(grid, 0, n - 1, j, m - 1);
            for (int i = 0; i < n; i++) {
                int second = area(grid, 0, i, 0, j - 1);
                int third  = area(grid, i + 1, n - 1, 0, j - 1);
                ans = min(ans, first + second + third);
            }
        }

        // -------- Partition 5: Divide into 3 vertical columns --------
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                int first  = area(grid, 0, n - 1, 0, i);
                int second = area(grid, 0, n - 1, i + 1, j);
                int third  = area(grid, 0, n - 1, j + 1, m - 1);
                ans = min(ans, first + second + third);
            }
        }

        // -------- Partition 6: Divide into 3 horizontal rows --------
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int first  = area(grid, 0, i, 0, m - 1);
                int second = area(grid, i + 1, j, 0, m - 1);
                int third  = area(grid, j + 1, n - 1, 0, m - 1);
                ans = min(ans, first + second + third);
            }
        }

        return ans;
    }
};