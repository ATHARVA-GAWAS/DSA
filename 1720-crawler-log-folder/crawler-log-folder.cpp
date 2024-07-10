class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt=0;

        for(auto it:logs){
            if(it=="../" ){
                if( cnt>0){
                    cnt--;
                }
                
            }
            else if(it!="./"){
                cnt++;
            }
        }
        return cnt;
    }
};