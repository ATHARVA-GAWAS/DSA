class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string temp="";
        string ans="";
        //reverse traversal
        for(int i=n-1;i>=0;i--){
            if(s[i]!=' '){         // skip spaces and include letters only to temp string inorder to get words (since we are traversing in the reverse order, we get reversed words)
                temp+=s[i];
            }
            if(temp.size()>0 && s[i]==' '){             //if we encounter space between words, we reverse the words and put them in ans string
                reverse(temp.begin(),temp.end());
                ans+=temp;
                temp="";
                if(i!=0){
                    ans+=' ';
                }
            }
        }
       
        reverse(temp.begin(),temp.end());    //handle first word of the string that doesnt get included during above process
        ans+=temp;
        if(ans[ans.size()-1]==' '){
            ans.erase(ans.size()-1);
        }
        
        return ans;
    }
};