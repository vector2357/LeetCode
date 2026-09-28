class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, parCount = 0;

        for (char c : s) {
            if (c == '(') {
                parCount++;
                ans = max(ans, parCount);
            }
            else if (c == ')') {
                parCount--;
            }
        }

        return ans;
    }
};