class Solution {
    void f(int open,int close,string temp,vector<string>&ans){
        if(open==0 && close==0){
            ans.push_back(temp);
        }

        if(open>0){
            f(open-1,close,temp+"(",ans);
        }

        if(close>open){
            f(open,close-1,temp+")",ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        f(n,n,"",ans);
        return ans;
    }
};