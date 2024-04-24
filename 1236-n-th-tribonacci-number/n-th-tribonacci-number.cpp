class Solution {
public:
    int t[38]; // Array with -1
    int solve(int n){
        if(n==0) // Base Cases
            return 0;
        if(n==1 || n==2) // Base Cases
            return 1;
        if(t[n]!=-1) // If found in array then return the answer
            return t[n];
        return t[n]=solve(n-1)+solve(n-2)+solve(n-3); // Reducing the Input 
    }
    int tribonacci(int n) {
        memset(t,-1,sizeof(t)); // Setting the array with -1 
        return solve(n); // Calling the function
    }
};