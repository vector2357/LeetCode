class Solution {
public:
    bool hasAlternatingBits(int n) {
        bitset<31> bits{(unsigned long long)n};

        int lg = ceil(log2(n));

        for (int i=1; i<lg; i++) {
            if (bits[i] == bits[i-1]) return false;
        }
        return true;
    }
};