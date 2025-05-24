class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n=words.size();

        vector<int> ans;

        for(int i=0;i<n;i++){
            unordered_set<char> st;

            for(auto it:words[i]){
                st.insert(it);
            }

            if(st.find(x)!=st.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};