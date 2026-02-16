class Solution {
public:
    int reverseBits(int n) {
        bitset<32> bits{(unsigned long long)n};
        bitset<32> ans;

        for (int i=0; i<32; i++) {
            ans[i] = bits[31-i];
        }
        return static_cast<int>(ans.to_ulong());
    }
};