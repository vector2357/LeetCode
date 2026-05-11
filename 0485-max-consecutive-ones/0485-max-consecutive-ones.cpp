class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, tmp = 0;

        for (int i=0; i<nums.size(); i++) {
            if (nums[i]) {
                tmp++;
            }
            else {
                ans = max(ans, tmp);
                tmp = 0;
            }
        }
        return max(ans, tmp);
    }
};