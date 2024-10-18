class Solution {
public:
    int ans=0;

    void recursive(int idx, int current, int total, vector<int>& nums) {
        if(idx == nums.size()) return;

        int x = current | nums[idx];
        if(x == total) ans++;

        recursive(idx+1, x, total, nums);
        recursive(idx+1, current, total, nums);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int bitwise=0;

        for(auto& num : nums) {
            bitwise |= num;
        }

        recursive(0, 0, bitwise, nums);

        return ans;
    }
};