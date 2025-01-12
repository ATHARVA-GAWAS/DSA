class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();

        if(n%2!=0){
            return false;
        }

        int balanced=0;

        for(int i=0;i<n;i++){
            if(s[i]=='(' || locked[i]=='0'){
                balanced++;
            }
            else{
                balanced--;
            }

            if(balanced<0){
                return false;
            }
        }

        balanced=0;

        for(int i=n-1;i>=0;i--){
            if(s[i]==')' || locked[i]=='0'){
                balanced++;
            }
            else{
                balanced--;
            }

            if(balanced<0){
                return false;
            }
        }

        return true;
    }
};