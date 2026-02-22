class Solution {
public:
    int binaryGap(int n) {
        string s=bitset<32>(n).to_string();

        int prev=-1,cur=0;

        int ans=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                cur = i;

                if(prev!=-1){
                    ans=max(ans,cur-prev);
                }
                
                prev=cur;

            }
        }

        return ans;
    }
};