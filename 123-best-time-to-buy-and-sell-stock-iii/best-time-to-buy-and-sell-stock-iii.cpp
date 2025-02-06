class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        vector<vector<int>> ahead(2,vector<int>(3,0)),cur(2,vector<int>(3,0));

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy==1){
                        cur[buy][cap]=max(-prices[ind]+ahead[0][cap],0+ahead[1][cap]);
                    }
                    else{
                        cur[buy][cap]=max(prices[ind]+ahead[1][cap-1],0+ahead[0][cap]);
                    } 
                }
                ahead=cur;
            }
        }
       
        return ahead[1][2];
    }
};