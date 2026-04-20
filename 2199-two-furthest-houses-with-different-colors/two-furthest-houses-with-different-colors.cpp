class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();

        int l=0,r=n-1;

        while(colors[0]==colors[r]){
            r--;                        //Leftmost house
        }

        while(colors[n-1]==colors[l]){
            l++;                        //Rightmost house
        }

        return max(n-l-1, r);
    }
};