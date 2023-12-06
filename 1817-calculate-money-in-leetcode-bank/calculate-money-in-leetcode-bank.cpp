class Solution {
public:
    int totalMoney(int n) {
        int items  = n / 7;
        int first  = 28;
        int last   = 28 + (items - 1) * 7; //Tn = a1 + (n-1)*d
        
        int arithmeticSum = items * (first + last) / 2; //Sn = n/2(a1 + an)
        
        //Final week remaining days
        int monday_money = 1 + items;
        int finalWeek    = 0;
        
        for (int day = 1; day <= (n % 7); day++) { //This loop will Never iterate more than 6 ~ O(1)
            finalWeek += monday_money++;
        }
        
        return arithmeticSum + finalWeek;
    }
};
