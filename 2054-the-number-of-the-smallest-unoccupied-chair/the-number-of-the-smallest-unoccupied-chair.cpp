class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> index(n);
        iota(index.begin(), index.end(), 0);
        priority_queue<int, vector<int>, greater<int>> availChairs(index.begin(), index.end());
        priority_queue<pair<int, int>> endTime;
        sort(index.begin(), index.end(), [&](int &i, int &j) {
            return times[i][0] < times[j][0];
        });
        for(int i = 0; i < n; i++) {
            while(!endTime.empty() && -endTime.top().first <= times[index[i]][0]) {
                availChairs.push(endTime.top().second);
                endTime.pop();
            }
            if(targetFriend == index[i]) return availChairs.top();
            endTime.push({-times[index[i]][1], availChairs.top()});
            availChairs.pop();
        }
        return n - 1;
    }
};