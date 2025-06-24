class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();

        unordered_set<int> st;

        vector<int> ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if( abs(i-j)<=k && nums[j]==key){
                    st.insert(i);
                }
            }
        }

        for(auto it:st){
            ans.push_back(it);
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};