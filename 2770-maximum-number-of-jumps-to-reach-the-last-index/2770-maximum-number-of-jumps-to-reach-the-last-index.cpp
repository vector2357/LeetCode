class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pd(n, 0);
        
        for (int i=0; i<n-1; i++) {
            if (i && !pd[i]) continue;
            for (int j=i+1; j<n; j++) {
                if (abs(nums[i]-nums[j]) <= target) {
                    pd[j] = max(pd[j], pd[i]+1);
                }
            }
        }
        return (pd[n-1]) ? pd[n-1] : -1;
    }
};