class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int m=25*n/100;
        unordered_map<int,int> mp;
        for(int &num: arr){
            mp[num]++;
            if(mp[num]>m){
                return num;
            }
        }
        return -1;
        
    }
};