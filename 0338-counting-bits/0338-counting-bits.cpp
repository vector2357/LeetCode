class Solution {
public:
    vector<int> countBits(int n) {
        int exp = 1;
        vector<int> ans(n+1, 0);

        while (exp <= n) {
            ans[exp] = 1;
            exp *= 2;
        }

        for (int i=1, j=3; j<=n; j++) {
            if (ans[j]) {
                i=1;
            }
            else {
                ans[j] += 1+ans[i];
                i++;
            }
        }
        return ans;
    }
};