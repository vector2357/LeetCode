class Solution {
public:
    vector<vector<int>> ans;

    void permutation(vector<int>& nums, int idx) {
        if(idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i=idx; i<nums.size(); i++) {
            swap(nums[idx], nums[i]);
            permutation(nums, idx+1);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        permutation(nums, 0);

        return ans;
    }
};