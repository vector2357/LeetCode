class Solution {
public:
    int countTriples(int n) {
        int ans=0;
        for (int c=2; c<=n; c++) {
            for (int b=1; b<c; b++) {
                int a = sqrt(c*c - b*b);
                if (a*a == c*c-b*b) {
                    ans ++;
                }
            }
        }
        return ans;
    }
};