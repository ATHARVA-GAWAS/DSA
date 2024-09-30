class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int> pq;

        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }

        while(pq.size()>1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            int x =first-second;
            if (x > 0) {
                pq.push(x);
            }
        }

        if(!pq.empty()){
            int ans=pq.top();
            return ans;
        }
        return 0;
    }
};