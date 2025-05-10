class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        long long sum1=0,sum2=0,zero1=0,zero2=0;

        for(int &it:nums1){
            sum1+=it;

            if(it==0){  //to get minimum sum, add smallest positive i.e. 1
                zero1++;
                sum1++;
            }
        }

        for(int &it:nums2){
            sum2+=it;

            if(it==0){  //to get minimum sum, add smallest positive i.e. 1
                zero2++;
                sum2++;
            }
        }

        if((sum1<sum2 && zero1==0) || (sum2<sum1 && zero2==0)){
            return -1;
        }

        return max(sum1,sum2);
    }
};