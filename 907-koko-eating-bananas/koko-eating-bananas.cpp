class Solution {
    bool canEat(vector<int>&piles,int currhour,int h){
        int actualhour=0;

        for(int &x:piles){
            actualhour+=x/currhour;

            if(x%currhour!=0){
                actualhour++;
            }
        }

        return actualhour<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();

        int low=1,high=*max_element(piles.begin(),piles.end());

        while(low<high){
            int mid=low+(high-low)/2;
            if(canEat(piles,mid,h)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }

        return low;
    }
};