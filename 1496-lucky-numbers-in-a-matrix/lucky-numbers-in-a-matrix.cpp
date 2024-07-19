class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();

        vector<int>answer;
        vector<int>min_row;
        vector<int>max_col;
        //find min in each row;
        for(int  i=0;i<n;i++){
            int mini=matrix[i][0];
            for(int j=1;j<m;j++){
                mini=min(mini,matrix[i][j]);
            }
            min_row.push_back(mini);
        }

        //find max in each column;
        for(int j=0;j<m;j++){
            int maxi=matrix[0][j];
            for(int i=1;i<n;i++){
                maxi=max(maxi,matrix[i][j]);
            }
            max_col.push_back(maxi);
        }

        //final step for creating result;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==min_row[i]&&matrix[i][j]==max_col[j]){
                    answer.push_back(matrix[i][j]);
                }
            }
        }

        return answer;
    }
};