class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==nums[nums.size()-1]) return nums.size()-i;
        } 
        return 1;
    }
};