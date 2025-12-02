class Solution {
    int mod=1e9+7;
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n=points.size();
        
        unordered_map<int, int> mp; //y -> count

        for(auto &point : points) {
            int y = point[1];
            mp[y]++;
        }

        long long res=0;

        long long prevhorizontallines=0;

        for(auto it:mp){
            int cnt=it.second;

            long long horizontallines=(long long) cnt*(cnt-1)/2;   //count c2

            res+=horizontallines*prevhorizontallines;

            prevhorizontallines+=horizontallines;
        }

        return res%mod;
    }
};