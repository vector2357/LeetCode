class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<long long>> mp;
        vector<long long> ans(nums.size());

        for (int i=0; i<nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        for (auto &m : mp) {
            long long sum = 0;
            for (int i=0; i<m.second.size(); i++) {
                sum += m.second[i];
            }
            long long leftSum = 0;

            for (int i=0; i<m.second.size(); i++) {
                long long rightSum = sum - leftSum - m.second[i];

                long long left = 1LL * m.second[i] * i - leftSum;
                long long right = rightSum - 1LL * m.second[i] * (m.second.size()-i-1);

                ans[m.second[i]] = left + right;
                leftSum += m.second[i];
            }
        }
        return ans;
    }
};