class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> ahead(2,0);
        vector<int> after(2,0);
        vector<int> cur(2,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                if(buy==1){
                    cur[buy]=max(-prices[ind]+ahead[0],0+ahead[1]);
                }
                else{
                    cur[buy]=max(prices[ind]+after[1],0+ahead[0]);
                }
            }
            after=ahead;
            ahead=cur;
        }
        return cur[1];
    }
};