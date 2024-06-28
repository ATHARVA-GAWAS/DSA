class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);

        for(auto &it : roads) {
            int u = it[0];
            int v = it[1];

            degree[u]++;
            degree[v]++;
        }

        sort(begin(degree), end(degree)); //ascedning order

        long long value = 1;
        long long sum   = 0;

        for(int i = 0; i < n; i++) {
            sum += (degree[i] * value);
            value++;
        }

        return sum;
    }
};