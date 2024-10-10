class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int> pq;

        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }

       while(pq.size()>1){
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();

        int x=a-b;
        if(x>0){
            pq.push(x);
        }
       }

       int ans;

       while(!pq.empty()){
        ans=pq.top();
        pq.pop();

        return ans;
       }
        return 0;
    }
};