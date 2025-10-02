class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int cnt= numBottles;

        while (numBottles >= numExchange) {
            numBottles-=numExchange;
            numBottles++;   //gain 1 bottle after exchange

            cnt++;  //no. of bottles drunk increased by 1

            numExchange++;   //increase numExchange requirement by 1
        }
        
        return cnt;
    }
};