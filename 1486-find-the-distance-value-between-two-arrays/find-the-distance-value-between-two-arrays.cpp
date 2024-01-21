class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n=arr1.size();
        int m=arr2.size();
        int cnt=0;
        sort(arr2.begin(),arr2.end());
        for(int it: arr1){
            if(upper_bound(arr2.begin(),arr2.end(),it+d)==lower_bound(arr2.begin(),arr2.end(),it-d)){
                cnt++;
            }
        }
        return cnt;
    }
};