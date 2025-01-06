class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();

        vector<int> arr;

        for(auto it: boxes){
            arr.push_back(it-'0');
        }

        unordered_set<int> st;

        for(int i=0;i<n;i++){
            if(arr[i]==1){
                st.insert(i);
            }
        }        

        vector<int> res(n,0);

        for(int i=0;i<n;i++){
            for(auto it:st){
                res[i]+=abs(i-it);
            }
        }

        return res;
    }
};