class Solution {
public:
    int binaryGap(int n) {
        bitset<32> bits{(unsigned long long)n};

        int longest = 0, pos = -1;
        for (int i=0; i<32; i++) {
            if (bits[i]) {
                if (pos != -1) {
                    longest = max(longest, i-pos);
                }
                pos = i;
            }
        }
        return longest;
    }
};