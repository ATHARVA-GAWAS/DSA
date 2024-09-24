class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st;

        int maxi=0;

        for(int it:arr1){
            string str=to_string(it);
            for(int i=1;i<=str.size();i++){
                st.insert(str.substr(0,i));
            }
        }

        for(int it: arr2){
            string str=to_string(it);
            for(int i=1;i<=str.length();i++){
                if(st.find(str.substr(0,i))!=st.end()){
                    maxi=max(maxi,i);
                }
                else{
                    break;
                }
            }
        }
        return maxi;
    }
};