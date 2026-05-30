class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 100;

        for (int i=0; i<nums.size(); i++) {
            int num = nums[i];
            nums[i] = 0;
            while (num) {
                nums[i] += num%10;
                num /= 10;
            }
            ans = min(ans, nums[i]);
        }
        return ans;
    }
};