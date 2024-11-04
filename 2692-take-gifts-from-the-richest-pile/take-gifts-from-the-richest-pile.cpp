class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans=0;

        int n=gifts.size();

        priority_queue<int> pq;

        for(auto it:gifts){
            pq.push(it);
        }

        while(k--){
            int x=pq.top();
            pq.pop();
            x=sqrt(x);

            pq.push(x);
        }

        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }

        return ans;
    }
};