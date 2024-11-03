class Solution {
public:
    vector<int> DP;

    bool rec(int idx, vector<int>& nums) {
        if(idx >= nums.size()-1) return true;
        if(DP[idx] != -1) return DP[idx];

        for(int i=1; i<=nums[idx]; i++) {
            if(rec(idx+i, nums)) return DP[idx] = true;
        }

        return DP[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        DP.assign(nums.size()+1, -1);
        return rec(0, nums);
    }
};