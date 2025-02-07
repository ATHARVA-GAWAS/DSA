class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        vector<int> ahead(2,0),cur(2,0),after(2,0);

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    cur[buy]=max(-prices[ind]+after[0],0+after[1]);
                }
                else{
                    cur[buy]=max(prices[ind]+ahead[1],0+after[0]);
                }
            }
            ahead=after;
            after=cur;
        }

        return cur[1];
    }
};