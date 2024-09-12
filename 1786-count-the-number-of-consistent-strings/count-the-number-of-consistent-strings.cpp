class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st;

        for(auto it:allowed){
            st.insert(it);
        }
        int ans=0;
        bool x=false;
        for(auto it:words){
            x=true;
            for(int i=0;i<it.size();i++){
                if(st.find(it[i])==st.end()){
                    x=false;
                    break;
                }
            }
            if(x){
                ans++;
            }
        }

        return ans;
    }
};