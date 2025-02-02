class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n+1,0),cur(n+1,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    cur[j]=1;
                }

                else{
                    int a=0,b=0;

                    if(i>0){
                        a=prev[j];
                    }
                    if(j>0){
                        b=cur[j-1];
                    }

                    cur[j]=a+b;
                }
                prev=cur;
            }
        }

        return prev[n-1];
    }
};