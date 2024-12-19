class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();

        int cursum=0,expectedsum=0,chunks=0;

        for(int i=0;i<n;i++){
            cursum+=arr[i];
            expectedsum+=i;

            if(cursum==expectedsum){
                chunks++;
            }
        }

        return chunks;
    }
};
