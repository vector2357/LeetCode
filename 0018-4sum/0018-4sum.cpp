class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size() < 4) return ans;
        sort(nums.begin(), nums.end());
        set<vector<int>> aux;
        
        for(int i=0; i<nums.size()-3; i++) {
            for(int j=i+1; j<nums.size()-2; j++) {
                int l = j+1, r = nums.size()-1;

                while(l < r) {
                    long sum = (long)nums[i] + (long)nums[j] + (long)nums[l] + (long)nums[r];

                    if(sum == target) {
                        if(!aux.count({nums[i], nums[j], nums[l], nums[r]})) {
                            ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                            aux.insert({nums[i], nums[j], nums[l], nums[r]});
                        }
                        l++;
                        r--;
                    }
                    else {
                        if(sum < target) {
                            l++;
                        }
                        else {
                            r--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};