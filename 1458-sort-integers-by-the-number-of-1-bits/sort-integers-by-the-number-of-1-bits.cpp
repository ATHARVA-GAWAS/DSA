class Solution {
    int countOneBits(int num){
        int count=0;;
        while(num!=0){
            count+=num & 1;
            num>>=1;
        }
        return count;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto cmp = [&](int &a, int &b) {
            
            int count_a = countOneBits(a);
            int count_b = countOneBits(b);
            
            if(count_a == count_b){
                return a<b;
            }
                
            return count_a < count_b;  
        };

        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};