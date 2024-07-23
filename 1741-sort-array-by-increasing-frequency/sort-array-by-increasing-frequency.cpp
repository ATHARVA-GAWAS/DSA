class Solution {
    bool static cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.second==b.second){
            return a.first>b.first;
        }
        return a.second<b.second;
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;

        for(int it:nums){
            mp[it]++;
        }

        vector<pair<int,int>> temp;

        for(auto it: mp){
            auto x=make_pair(it.first,it.second);
            temp.push_back(x);
        }

        sort(temp.begin(),temp.end(),cmp);

        vector<int> ans;

        for(auto it:temp){
            int k=it.second;
            while(k--){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};