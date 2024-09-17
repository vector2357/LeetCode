class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size()-2; i++) {
            for(int j=i+1, k=nums.size()-1; j<k;) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else {
                    if(nums[j] + nums[k] + nums[i] < 0) {
                        j++;
                    }
                    else {
                        k--;
                    }
                }
            }
        }

        for(vector<int> it : s) {
            v.push_back(it);
        }

        return v;
    }
};