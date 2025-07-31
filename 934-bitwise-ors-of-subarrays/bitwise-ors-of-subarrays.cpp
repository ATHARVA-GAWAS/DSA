class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n=arr.size();

        unordered_set<int> ans;
        unordered_set<int> prev;

        for(int i=n-1;i>=0;i--){
            unordered_set<int> curr;

            curr.insert(arr[i]);

            for(int it:prev){
                curr.insert(it|arr[i]);
            }

            prev=curr;

            ans.insert(curr.begin(),curr.end());
        }

        return ans.size();
    }
};