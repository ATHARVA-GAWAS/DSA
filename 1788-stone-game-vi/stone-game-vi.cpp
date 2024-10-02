class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        priority_queue<pair<int,pair<int,int>>> pq;

        int a=0,b=0;

        for(int i=0;i<aliceValues.size();i++){
            pq.push({aliceValues[i]+bobValues[i],{aliceValues[i],bobValues[i]}});
        }

        while(!pq.empty()){
            a+=pq.top().second.first;
            pq.pop();

            if(!pq.empty()){
                b+=pq.top().second.second;
                pq.pop();
            }
        }
        if(a==b){
            return 0;
        }
        else if(b>a){
            return -1;
        }

         else{
            return 1;
        }
    }
};