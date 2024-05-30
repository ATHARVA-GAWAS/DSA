class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        vector<int> prefXor(arr.begin(),arr.end());
        prefXor.insert(prefXor.begin(),0);

        int n=prefXor.size();

        for(int i=1;i<n;i++){
            prefXor[i]^=prefXor[i-1];
        }

        int triplets=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(prefXor[j]==prefXor[i]){
                    triplets+=j-i-1;
                }
            }
        }
        return triplets;
    }
};