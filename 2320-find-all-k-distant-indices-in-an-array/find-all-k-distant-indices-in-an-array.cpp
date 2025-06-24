class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();

        unordered_set<int> st;

        vector<int> ans;

        for(int j=0;j<n;j++){
            if(nums[j]==key){
                int start=max(0,j-k);
                int end=min(n-1,j+k);

                for(int i=start;i<=end;i++){
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