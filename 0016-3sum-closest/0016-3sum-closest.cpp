class Solution {
public:
    int ans=1e8;

    void recursive(int idx, int current, int group, int target, vector<int>& nums) {
        if(group == 3) {
            if(abs(current-target) < abs(ans-target)) {
                ans = current;
            }
            return;
        }
        if(idx==nums.size()) return;
    
        recursive(idx+1, current+nums[idx], group+1, target, nums);
        recursive(idx+1, current, group, target, nums);        
    }

    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()==3) return nums[0]+nums[1]+nums[2];

        recursive(0, 0, 0, target, nums);
        return ans;
    }
};