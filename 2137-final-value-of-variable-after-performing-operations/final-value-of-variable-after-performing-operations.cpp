class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n=operations.size();

        int cnt=0;

        for(auto it:operations){
            if(it[0]=='+' || it[2]=='+'){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        return cnt;
    }
};