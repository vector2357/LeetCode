class Solution {
public:
    unsigned long long comb(int n, int k) {
        int i, j;
        unsigned long long num=1, den=1;
        for(i=n, j=2; i>k && j<=k; i--) {
            num *= i;
            if(num%j == 0) {
                num /= j;
                j++;
            }
        }
        for(; i>k; i--) {
            num *= i;
        }
        for(; j<=k; j++) {
            den *= j;
        }
        return num/den;
    }

    int numTrees(int n) {
        // Número de Catalan
        return (int)(comb(2*n, n) / (n+1));
    }
};