class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();

        int res=INT_MAX;

        for(int i=0;i<n;i++){
            if(words[i]==target){
                int st=abs(startIndex-i);
                int ct=abs(n-st);

                res=min({res,st,ct});
            }
        }

        return res!=INT_MAX? res:-1;
    }
};