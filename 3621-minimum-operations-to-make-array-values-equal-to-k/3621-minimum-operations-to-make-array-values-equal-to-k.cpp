class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> s;

        for(int i=0; i<nums.size(); i++) {
            s.insert(nums[i]);
        }

        auto it = s.begin();

        if((*it) < k) {
            return -1;
        }
        if((*it) == k) {
            return s.size()-1;
        }
        return s.size();
    }
};