class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string>ans(n,"");

        priority_queue<pair<int,int>>pq;

        for(int i=0;i<n;i++){
            pq.push({score[i],i});
        }
        
        int ind;
        if(!pq.empty()){
            ind=pq.top().second;
            pq.pop();
            ans[ind]="Gold Medal";
        }

        if(!pq.empty()){
            ind=pq.top().second;
            pq.pop();
            ans[ind]="Silver Medal";
        }

        if(!pq.empty()){
            ind=pq.top().second;
            pq.pop();
            ans[ind]="Bronze Medal";
        }

        int x=4;

        while(!pq.empty()){
            ind=pq.top().second;
            pq.pop();
            ans[ind]=to_string(x);
            x++;
        }
        return ans;
    }
};