class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0, sum=0, vis[100001]={0};
        set<int> s;
        for(int i=0; i<nums.size(); i++) {
            s.insert(nums[i]);
            vis[nums[i]]++;
            sum+=nums[i];
            if(i>=k-1) {
                if(s.size()==k) {
                    ans = max(ans, sum);
                }
                vis[nums[i-(k-1)]]--;
                if(vis[nums[i-(k-1)]] == 0) {
                    s.erase(nums[i-(k-1)]);
                }
                sum-=nums[i-(k-1)];
            }
        }
        return ans;
    }
};