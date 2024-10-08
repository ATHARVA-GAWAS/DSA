class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;

        double ans = 0;

        for(int i = 0; i < classes.size(); i++) {

            double diff = (classes[i][0] + 1.0) / (classes[i][1] + 1.0) - classes[i][0] * 1.0 / classes[i][1];
            ans += classes[i][0] * 1.0 / classes[i][1];
            pq.push({diff, i});
        }
        
        while(extraStudents--) {

            auto [d, i] = pq.top();
            pq.pop();
            classes[i][0]++;
            classes[i][1]++;
            double diff = (classes[i][0] + 1.0) / (classes[i][1] + 1.0) - classes[i][0] * 1.0 / classes[i][1];
            ans += d;
            pq.push({diff, i});
        }
        
        return ans / classes.size();
    }
};