class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();

        sort(events.begin(),events.end());

        priority_queue<int,vector<int>,greater<int>> pq;

        int res=0;
        int day=0;

        int i=0;

        while(i<n || !pq.empty()){
            if(pq.empty()){
                day=events[i][0];
            }

            //add all events starting today
            while(i<n && events[i][0]==day){
                pq.push(events[i][1]);
                
                i++;
            }

            //remove expired events
            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }

            //attend one event
            if(!pq.empty()){
                pq.pop();

                res++;
            }

            day++;
        }

        return res;
    }
};