class Solution {
    bool difference_array(vector<int>&nums, vector<vector<int>>&queries,int k,int n,int q){
        vector<int> diff(n,0);

        for(int i=0;i<=k;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int x=queries[i][2];

            diff[l]+=x;

            if(r+1<n){
                diff[r+1]=diff[r+1]-x;
            }
        }

        int cursum=0;

        for(int i=0;i<n;i++){
            cursum+=diff[i];

            diff[i]=cursum;

            if(nums[i]-diff[i]>0){
                return false;
            }
        }

        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();

        auto lambda=[](int x){
            return x==0;
        };

        if(all_of(nums.begin(),nums.end(),lambda)){
            return 0;
        }

        int l=0,r=q-1,k=-1;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(difference_array(nums,queries,mid,n,q)==true){
                k=mid+1;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return k;
    }
};