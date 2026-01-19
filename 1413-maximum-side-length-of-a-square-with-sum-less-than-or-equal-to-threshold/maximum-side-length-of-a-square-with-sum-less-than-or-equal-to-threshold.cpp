class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        // Build prefix sum (column-wise)
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] += mat[i - 1][j];
            }
        }

        // Build prefix sum (row-wise)
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                mat[i][j] += mat[i][j - 1];
            }
        }

        int ans = 0;

        // Try all squares
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < min(m - i, n - j); k++) {
                    int sum = mat[i + k][j + k];

                    if (i > 0 && j > 0) {
                        sum -= mat[i - 1][j + k] + mat[i + k][j - 1] - mat[i - 1][j - 1];
                    } 
                    else if (i > 0) {
                        sum -= mat[i - 1][j + k];
                    } 
                    else if (j > 0) {
                        sum -= mat[i + k][j - 1];
                    }

                    if (sum <= threshold) {
                        ans = max(ans, k + 1);
                    }
                }
            }
        }

        return ans;
    }
};