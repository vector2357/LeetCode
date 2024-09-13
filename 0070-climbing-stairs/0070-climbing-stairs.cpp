class Solution {
public:
    int climbStairs(int n) {
        int fib[50];
        fib[1]=1;
        fib[2]=2;
        for(int i=3; i<=n; i++) {
            fib[i] = fib[i-1]+fib[i-2];
        }
        return fib[n];
    }
};