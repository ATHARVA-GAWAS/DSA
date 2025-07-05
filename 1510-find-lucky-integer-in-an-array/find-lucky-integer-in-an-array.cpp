class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;

        int ans=INT_MIN;

        for(auto it:arr){
            mp[it]++;
        }

        for(auto it:mp){
            if(it.first==it.second){
                ans=max(ans,it.first);
            }
        }

        return ans==INT_MIN?-1:ans;
    }
};