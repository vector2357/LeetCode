class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int arr[101] = {0}, i;

        for(i=nums.size()-1; i>=0 && !arr[nums[i]]; i--) {
            arr[nums[i]]++;
        }
        int ans = (i+1)/3;
        if((i+1)%3) ans++;
        return ans;
    }
};