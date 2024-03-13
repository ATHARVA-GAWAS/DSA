class Solution {
public:
    int pivotInteger(int n) {
        int leftsum=n*(n+1)/2;
        int rightsum=0;

        while(leftsum>rightsum){
            rightsum+=n;
            if(leftsum==rightsum){
                return n;
            }
            leftsum-=n;
            n--;
        }
        return -1;
    }
};