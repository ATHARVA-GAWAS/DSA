class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt=0;
        unordered_map<int,int> mp;
        for(int it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            int num = it.second;
            while(num) {
                if(num % 3 == 0){
                   num -= 3;
                } 
                else if(num >= 2){
                    num -= 2;
                } 
                else{
                     return -1;
                }  
                cnt++;
            } 
        }
       
        return cnt;
        
    }
};