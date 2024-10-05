class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cont = 0;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != val) {
                cont++;
                ans.push_back(nums[i]);
            }
        }

        for(int i=0; i<cont; i++) {
            nums[i] = ans[i];
        }

        return cont;
    }
};