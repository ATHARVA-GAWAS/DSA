class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int m=25*n/100;
        for(int i=0;i<n-m;i++){
            
            if(arr[i]==arr[i+m]){
                return arr[i];
            }
        }
        return -1;
        
    }
};