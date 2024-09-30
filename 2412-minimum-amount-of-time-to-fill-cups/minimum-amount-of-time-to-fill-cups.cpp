class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;

        for(int i=0;i<3;i++)
        {
            pq.push(amount[i]);
        }
        
        int count=0;
        while(pq.top()!=0)
        {
            int num1=pq.top();
            num1--;
            pq.pop();
            
            int num2=pq.top();
            num2--;
            pq.pop();
            
            pq.push(num1);
            pq.push(num2);
            
            count++;
        }
        
        return count;
    }
};