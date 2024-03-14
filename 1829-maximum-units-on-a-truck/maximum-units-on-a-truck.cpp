class Solution {
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1]>b[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int ans=0;
        for(auto it:boxTypes){
            
            if(truckSize>0){
                int temp=it[0];
                 while(temp != 0 && truckSize > 0){
                    ans += it[1];
                    temp--;
                    truckSize--;
                }
            }
        }
        return ans;
    }
};