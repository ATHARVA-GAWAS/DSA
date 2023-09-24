class Solution {
    double f(int poured,int i, int j,vector<vector<double>> &dp){
        if(i<0 || j<0 || i<j){
            return 0.0;
        }
        if(i==0 && j==0){
            return poured;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        double leftup,rightup;
        leftup=(f(poured,i-1,j-1,dp)-1)/2.0;
        rightup=(f(poured,i-1,j,dp)-1)/2.0;
        if(leftup<0){
            leftup=0;
        }
        if(rightup<0){
            rightup=0;
        }
        return dp[i][j]=leftup+rightup;
    }
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row+1,vector<double>(query_row+1,-1));
        return min(1.0,f(poured,query_row,query_glass,dp));
    }
};