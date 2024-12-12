class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n=gifts.size();

        priority_queue<int> pq;

        for(auto it:gifts){
            pq.push(it);
        }

        int x=k;

        long long ans=0;


        while(x--){
            long long a=pq.top();
            pq.pop();

            a=floor(sqrt(a));

            pq.push(a);
        }

        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }

        return ans;
    }
};