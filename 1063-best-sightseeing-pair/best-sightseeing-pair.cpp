class Solution {
public:
    int score=0;
    int f(int ind, vector<int>& values){
        if (ind<0){
            return 0;
        } 
    
        int x=values[ind], prev=f(ind-1, values);
        score=max(score, prev+x-ind);
        return max(prev, x+ind);
    }

    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();

        f(n-1, values);
        return score;
    }
};