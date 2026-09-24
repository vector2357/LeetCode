class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool flag = false;
        int n = digits.size();

        for (int i=n-1; i>=0 && !flag; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
            }
            else {
                digits[i]++;
                flag = true;
            }
        }
        if (flag) return digits;

        vector<int> ans = {1};
        ans.insert(ans.end(), digits.begin(), digits.end());

        return ans;
    }
};