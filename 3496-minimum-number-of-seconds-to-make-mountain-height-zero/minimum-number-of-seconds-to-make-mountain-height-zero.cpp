class Solution {
    bool f(int mountainHeight,const vector<int> &workerTimes,long long maxTime){
        long long tot=0;

        for(int time:workerTimes){
            long long l=0,h=mountainHeight, best=0;

            while(l<=h){
                long long mid=l+(h-l)/2;

                long long req=time*(mid*(mid+1))/2;

                if(req<=maxTime){
                    best=mid;
                    l=mid+1;
                }
                else{
                    h=mid-1;
                }
            }

            tot+=best;

            if(tot>=mountainHeight){
                return true;
            }
        }

        return tot>=mountainHeight;
    }
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l=0,h=LLONG_MAX;

        long long res=LLONG_MAX;

        while(l<=h){
            long long m=l+(h-l)/2;

            if(f(mountainHeight, workerTimes, m)){
                res=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }

        return res;
    }
};