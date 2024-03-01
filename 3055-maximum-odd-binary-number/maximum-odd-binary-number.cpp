class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.size();
        int a=count(s.begin(),s.end(),'1');
        int b=count(s.begin(),s.end(),'0');
        string ans= string(a-1,'1')+string(b,'0')+string(1,'1');
        return ans;
    }
};