class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        for (int i=n-1; i>=0; i--) {
            int num = nums[i];

            while (num) {
                ans.push_back(num%10);
                num /= 10;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};