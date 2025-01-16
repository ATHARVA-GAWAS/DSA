class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        unordered_map<int,long long> mp;

        for(auto it:nums1){ //occurences
            mp[it]+=m;
        }

        for(auto it:nums2){ //occurences
            mp[it]+=n;
        }

        int ans=0;

        for(auto it:mp){
            int num=it.first;
            long long freq=it.second;

            if(freq%2!=0){  //since the even frequency numbers would be 0 when xor'ed with each other
                ans=ans^num;
            }
        }

        return ans;
    }
};