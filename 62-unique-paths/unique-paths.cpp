class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(m+1,0);
        vector<int> cur(n+1,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    cur[j]=1;
                }
                else{
                    int left=0,up=0;

                    if(i>0){
                        left=prev[j];
                    }
                    if(j>0){
                        up=cur[j-1];
                    }

                    cur[j]=up+left;
                }
            }
            prev=cur;
        }

        return prev[n-1];
    }
};