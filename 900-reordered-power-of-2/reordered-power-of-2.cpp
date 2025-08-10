class Solution {
    auto cntdigit(int x){
        string s=to_string(x);

        sort(s.begin(),s.end());

        return s;
    }
public:
    bool reorderedPowerOf2(int n) {
        if(n==1){
            return true;
        }

        string target=cntdigit(n);

        for(int i=0;i<31;i++){
            if(cntdigit(1<<i)==target){
                return true;
            }
        }

        return false;
    }
};