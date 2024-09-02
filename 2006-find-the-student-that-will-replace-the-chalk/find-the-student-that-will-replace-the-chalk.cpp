class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {

        int n=chalk.size(),c=0;
        long long int total=0;

        for(auto it:chalk){
            total+=it;
        }

        k=k%total;

        int i=0;

        for(int i=0;i<chalk.size();i++){
            if(chalk[i]>k){
                return i;
            }else{
                k-=chalk[i];
            }
        }
        return -1;
    }
};