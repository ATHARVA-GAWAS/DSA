class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        
        //First comparing with only left neighbour from left to rigth direction in the array
        for(int i = 1; i<n; i++) {
            if(ratings[i] > ratings[i-1]){
                left[i] = max(left[i], left[i-1]+1);
            }   
        }
        
        //Then comparing with only right neighbour from right to left direction in the array
        for(int i = n-2; i>=0; i--) {
            if(ratings[i] > ratings[i+1]){
                right[i] = max(right[i], right[i+1]+1);
            }  
        }
        
        
        int result = 0;
        
        for(int i = 0; i<n; i++) {
            result += max(left[i], right[i]);
        }
        
        return result;
    }
};