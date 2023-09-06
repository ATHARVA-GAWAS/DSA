class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle.size();
        vector<int> after(n+1,0),cur(m+1,0);
        for(int j=0;j<n;j++){
            after[j] = triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                     if(i==n-1){
                            cur[j]=triangle[n-1][j];
                        }
                        
                    int d=triangle[i][j]+after[j];
                    int dg=triangle[i][j]+after[j+1];
                    cur[j]=min(d,dg);
                }
                after=cur;
        }
        return after[0];
    }
};