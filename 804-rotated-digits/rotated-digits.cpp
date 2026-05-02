class Solution {
public:
    int rotatedDigits(int n) {
        unordered_map<char,char> mp={
            {'0','0'},
            {'1','1'},
            {'6','9'},
            {'8','8'},
            {'9','6'},
            {'2','5'},
            {'5','2'},
            {'7','x'},
            {'4','x'},
            {'3','x'}
        };
        
        string temp;
        bool f=true;;
        int ans=0;
        
        for(int i=1;i<=n;i++){
            f=true;
            temp=to_string(i);
            string rot="";
            for(auto it:temp){
                if(mp[it]=='x'){
                    f=false;
                    break;
                }
                else{
                    rot += mp[it];
                }
            }
            if(f==true && rot!=temp){
                ans++;
            }
            
        }
        return ans;
    }
};