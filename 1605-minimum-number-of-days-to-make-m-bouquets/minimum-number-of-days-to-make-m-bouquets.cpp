class Solution {
public:
    bool ispossible(vector<int>&arr,int day,int m,int k){
        int n=arr.size();
        int cnt=0;
        int no_of_b=0;

        for(int i=0;i<n;i++){
            if(arr[i]<=day){
                cnt++;
            }
            else{
                no_of_b+=(cnt/k);
                cnt=0;
            }
        }

        no_of_b+=(cnt/k);

        return no_of_b>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll * k * 1ll;
        int n = bloomDay.size();

        if (val > n) return -1;

        int low = *min_element(begin(bloomDay), end(bloomDay));
        int high = *max_element(begin(bloomDay), end(bloomDay));

        while (low<=high) {
            int mid = (low + high) / 2;

            if(ispossible(bloomDay,mid,m,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return low;
    }
};