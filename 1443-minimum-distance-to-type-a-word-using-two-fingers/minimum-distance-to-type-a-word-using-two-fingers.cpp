class Solution {
    int dist(int i, int j){
        int ax=i/6,ay=i%6;              //since beyboard is a 6x6 grid as per diagram
        int bx=j/6,by=j%6;

        return abs(ax-bx)+abs(ay-by);
    }
    int f(string &word,int ind,int i, int j,vector<vector<vector<int>>> &dp){
        if(ind==word.size()){
            return 0;
        }

        if(dp[ind][i][j]!=-1){
            return dp[ind][i][j];
        }

        int curr=word[ind]-'A';

        int A=dist(i,curr)+f(word,ind+1,curr,j,dp);
        int B=dist(j,curr)+f(word,ind+1,i,curr,dp);

        return dp[ind][i][j]=min(A,B);
    }
public:
    int minimumDistance(string word) {
        int n=word.size();

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(26,vector<int>(26,-1)));

        int ans=INT_MAX;

        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                ans=min(ans,f(word,0,i,j,dp));
            }
        }

        return ans;
    }
};