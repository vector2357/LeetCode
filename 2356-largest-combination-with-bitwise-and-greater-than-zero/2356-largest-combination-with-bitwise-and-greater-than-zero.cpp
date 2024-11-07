class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;

        for(int i=0; i<24; i++) {
            int bits=0;

            for(bitset<24> bit : candidates) {
                bits += bit[i];
            }

            ans = max(ans, bits);
        }

        return ans;
    }
};