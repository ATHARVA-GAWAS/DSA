class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(), m=matrix[0].size(), ans=0;
        vector<int>v(m, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='1'){
                    v[j]++;
                }
                else{
                    v[j]=0;
                }
            }
            stack<int>s;
            int maxi=0;
            //for(int j=0; j<m; j++){cout<<v[j]<<" ";}cout<<endl;
            for(int j=0; j<=m; j++){
                while(!s.empty() && (j==v.size() || v[j]<=v[s.top()])){
                    int top=v[s.top()];
                    s.pop();
                    int breadth;
                    if(s.empty()){
                        breadth=j;
                    }
                    else{
                        breadth=j-1-s.top();
                    }
                    maxi=max(maxi, top*breadth);
                }
                s.push(j);
            }
            ans=max(ans, maxi);
            //cout<<maxi<<endl;
        }
        return ans;
    }
};