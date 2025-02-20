class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n= nums.size();

        string result="";

        for(int i=0;i<n;i++){
            char ch=nums[i][i];

            //if 0 make it 1, if not make it 0

            if(ch=='0'){
                result+='1';
            }
            else{
                result+='0';
            }
        }

        return result;
    }
};