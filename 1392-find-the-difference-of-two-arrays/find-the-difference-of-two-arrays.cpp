class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> v(2);

        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        
        unordered_set<int> res1;
        unordered_set<int> res2;

        for(int num : s1)
        {
            if(s2.find(num) == s2.end())
            {
                res1.insert(num);
            }
        }

        for(int num : s2)
        {
            if(s1.find(num) == s1.end())
            {
                res2.insert(num);
            }
        }

        v[0].assign(res1.begin(), res1.end());
        v[1].assign(res2.begin(), res2.end());

        return v;
    }
};