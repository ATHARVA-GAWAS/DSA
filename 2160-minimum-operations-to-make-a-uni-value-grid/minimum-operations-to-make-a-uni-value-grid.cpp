class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        int r = grid[0][0] % x;

        vector<int> list;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((grid[i][j] % x) != r){
                    return -1;
                }

                list.push_back(grid[i][j]);
            }
        }

        sort(list.begin(), list.end());

        int size = list.size();
        
        int mid = (size % 2 == 0) ? (size/2 - 1) : (size/2);

        int target = list[mid];
        int ans = 0;

        for (int num: list) {
            ans += (abs(target-num))/x;
        }

        return ans;
    }
};