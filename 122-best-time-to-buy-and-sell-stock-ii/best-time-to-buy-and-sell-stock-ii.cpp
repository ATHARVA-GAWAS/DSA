class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        vector<int> ahead(2,0),cur(2,0);

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                int profit=0;

                if(buy){
                    profit=max(-prices[ind]+ahead[0],0+ahead[1]);
                }
                else{
                    profit=max(prices[ind]+ahead[1],0+ahead[0]); 
                }

                cur[buy]=profit;
            }
            ahead=cur;
        }

        return ahead[1];
    }
};