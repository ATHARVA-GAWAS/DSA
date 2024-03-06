class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string temp="";
        string ans="";
        for(int i=n-1;i>=0;i--){
            if(s[i]!=' '){
                temp+=s[i];
            }
            if(temp.size()>0 && s[i]==' '){
                reverse(temp.begin(),temp.end());
                ans+=temp;
                temp="";
                if(i!=0){
                    ans+=' ';
                }
            }
        }
       
        reverse(temp.begin(),temp.end());
        ans+=temp;
        if(ans[ans.size()-1]==' '){
            ans.erase(ans.size()-1);
        }
        
        return ans;
    }
};