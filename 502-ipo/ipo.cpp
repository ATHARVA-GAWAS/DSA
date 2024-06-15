class Solution {
    struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    }
};
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        vector<pair<int, int>> arr;
        int n = profits.size();
        
        for (int i = 0; i < n; i++) {
            arr.push_back({profits[i], capital[i]});
        }
        sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });
        int i=0;
        while (k > 0) {
            while (i < n && arr[i].second <= w) {
                pq.push(arr[i]);
                i++;
            }
            if (pq.empty()) {
                break;
            }
            auto it = pq.top();
            pq.pop();
            w += it.first;
            k--;
        }
        return w;
    }
};