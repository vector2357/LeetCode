class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for (int i=0, j=0; j<nums2.size() && i<nums1.size(); i++) {
            while (j<nums2.size() && nums2[j] >= nums1[i]) j++;
            ans = max(ans, j-i-1);
        }
        return ans;
    }
};