class Solution {
    int width;
    int f(int ind,int remWidth,int maxheight,vector<vector<int>>& books,vector<vector<int>> &dp){
        int n=books.size();
        if(ind>=n){
            return maxheight;
        }
        if(dp[ind][remWidth]!=-1){
            return dp[ind][remWidth];
        }
        int pick=INT_MAX,notpick=INT_MAX;

        if(books[ind][0]<=remWidth){
            pick= f(ind+1,remWidth-books[ind][0], max(maxheight,books[ind][1]),books,dp);
        }
        notpick=maxheight+f(ind+1,width-books[ind][0],books[ind][1],books,dp);
        return dp[ind][remWidth]=min(pick,notpick);
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        width=shelfWidth;

        vector<vector<int>> dp(n+1,vector<int>(shelfWidth+1,-1));
        return f(0,shelfWidth,0,books,dp);
    }
};