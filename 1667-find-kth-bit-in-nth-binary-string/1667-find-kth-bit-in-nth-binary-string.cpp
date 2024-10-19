class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1) return '0';

        int sz = pow(2, n)-1;
        char ans='0';
        vector<char> v;
        v.push_back('0');

        for(int i=1, j=-1; i<sz; i++, j--) {
            if(j == -1) {
                v.push_back('1');
                j = i;
            }
            else {
                if(v[j] == '0') {
                    v.push_back('1');
                }
                else {
                    v.push_back('0');
                }
            }
            if(i == k-1) {
                ans = v[i];
                break;
            }
        }
        return ans;
    }
};