class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> ans;
        ans=heights;
        sort(ans.begin(),ans.end());
        int cnt=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=ans[i]){
                cnt++;
            }
        }
        return cnt;

    }
};