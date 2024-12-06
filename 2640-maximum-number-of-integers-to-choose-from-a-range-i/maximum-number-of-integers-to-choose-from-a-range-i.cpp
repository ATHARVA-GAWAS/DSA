class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st;

        for(auto it:banned){
            st.insert(it);
        }   

        int sum=0;
        int cnt=0;

        for(int i=1;i<=n;i++){
            if(st.find(i)==st.end() && sum<=maxSum){

                if(sum+i<=maxSum){
                    sum+=i;
                    cnt++;
                }
                else{
                    continue;
                }
            }
        }

        return cnt;

    }
};