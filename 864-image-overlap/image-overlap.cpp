class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();

        vector<pair<int,int>> a,b;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]){
                    a.push_back({i,j});
                }
                if(img2[i][j]){
                    b.push_back({i,j});
                }
            }
        }

        map<pair<int,int>,int> cnt;

        int ans=0;

        for(auto x:a){
            for(auto y:b){
                pair<int,int> shift={y.first-x.first, y.second-x.second};

                ans=max(ans,++cnt[shift]);
            }
        }

        return ans;
    }
};