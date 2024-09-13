class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;

        for(auto it:queries){
            int res=arr[it[0]];
            for(int i=it[0]+1;i<=it[1];i++){
                res=res^arr[i];
            }
            ans.push_back(res);
        }

        return ans;
    }
};