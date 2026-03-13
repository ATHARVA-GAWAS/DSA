class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        using ll = long long;
        
        priority_queue<
            tuple<ll,ll,ll>,
            vector<tuple<ll,ll,ll>>,
            greater<>
        > pq;

        for(int t : workerTimes) {
            pq.push({t,1,t});  
            // {finishTime, nextMultiplier, baseTime}
        }

        ll ans = 0;

        for(int i=0;i<mountainHeight;i++) {
            auto [time,k,t] = pq.top();
            pq.pop();

            ans = max(ans,time);

            pq.push({time + (ll)t*(k+1), k+1, t});
        }

        return ans;
    }
};