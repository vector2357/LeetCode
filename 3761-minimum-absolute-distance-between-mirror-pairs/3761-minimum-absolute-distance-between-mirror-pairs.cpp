class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 1e6;
        for (int i=nums.size()-1; i>=0; i--) {
            int tmp = 0, num = nums[i];
            int x = pow(10, (int)log10(num));
            while (num) {
                tmp += x*(num%10);
                num /= 10;
                x /= 10;
            }
            if (mp.find(tmp) != mp.end()) {
                ans = min(ans, abs(mp[tmp]-i));
            }
            mp[nums[i]] = i;
        }
        
        return (ans == 1e6) ? -1 : ans;
    }
};