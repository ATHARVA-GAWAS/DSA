class Solution {
    bool is_symmetric(string temp){
        int n = temp.size();
        if (n % 2 != 0){
            return false; // odd number of digits not allowed
        } 

        int half = n / 2;
        int sum1 = 0, sum2 = 0;

        for (int i = 0; i < half; i++) {
            sum1 += temp[i] - '0';
            sum2 += temp[i + half] - '0';
        }

        return sum1 == sum2;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;

        for(int i=low;i<=high;i++){
            string temp=to_string(i);

            if(is_symmetric(temp)){
                cnt++;
            }
        }

        return cnt;
    }
};