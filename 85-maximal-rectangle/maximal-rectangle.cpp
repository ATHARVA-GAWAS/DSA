class Solution {
    int histogram(vector<int>& arr){
        stack<int>st;
        int maxi=0,n=arr.size();

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int curr=arr[st.top()]; 
                st.pop();

                int nse=i,pse=(st.empty()) ? -1 : st.top();

                maxi=max(maxi,curr*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int curr=arr[st.top()]; 
            st.pop();

            int nse=n,pse=(st.empty()) ? -1 : st.top();
            
            maxi=max(maxi,curr*(nse-pse-1));
        }
        return maxi;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),res=0;
        vector<int>height(m,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                } 
                else{
                    height[j]=0;
                } 
            }

            res=max(res,histogram(height));
        }
        return res;
    }
};