class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res;
        res=start^goal;

        bitset<32> a(res);
        string s=a.to_string();
        int ans=0;

        for(int i=0;i<32;i++){
            if(s[i]=='1'){
                ans++;
            }
        }
        return ans;
    }
};