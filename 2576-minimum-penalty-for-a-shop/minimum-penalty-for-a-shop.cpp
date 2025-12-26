class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();

        int res=0;

        int penalty=0,minpenalty=0;

        int k=0;

        for(auto it:customers){
            if(it=='Y'){
                penalty--;
            }
            else if(it=='N'){
                penalty++;
            }

            if(penalty<minpenalty){
                minpenalty=penalty;

                res=k+1;
            }

            k++;
        }

        return res;
    }
};