class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num);

        string maxi="",mini="";

        int n=s.size();
        char ele=' ';

        // Step 1: Find first non-9 digit for max replacement
        for(int i=0;i<n;i++){
            if(s[i]!='9'){
                ele=s[i];
                break;
            }
        }

        // Step 2: Replace that digit with 9 for max
        for(int i=0;i<n;i++){
            if(ele==s[i]){
                maxi+='9';
            }
            else{
                maxi+=s[i];
            }
        }

        // Step 3: Replace first digit for min with 0
        for(int i=0;i<n;i++){
            if(s[i]==s[0]){
                mini+='0';
            }
            else{
                mini+=s[i];
            }
        }

        // Step 4: Convert and calculate result
        return stoi(maxi)-stoi(mini);

    }
};