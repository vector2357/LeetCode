class Solution {
public:
    long long coloredCells(int n) {
        long long ans = (long long)n*n + (long long)(n-1)*(n-1);
        return ans;
    }
};