class Solution {
    int finddays(vector<int> &weights, int cap){
        int days=1;
        int load=0;

        int n=weights.size();

        for(int i=0;i<n;i++){
            if(load+weights[i]>cap){
                days++;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }

        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low<=high){
            int mid=low+(high-low)/2;

            int no_of_days=finddays(weights,mid);

            if(no_of_days<=days){
                high=mid-1;
            }

            else{
                low=mid+1;
            }
        }

        return low;
    }
};