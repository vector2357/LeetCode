class Solution {
public:
    int jump(vector<int>& nums) {
        int ans=1, i=0, n=nums.size();

        if(n==1) return 0;
        
        while(i != n-1) {
            if(nums[i] >= n-1-i) return ans;
            int maxx=-1, id;
            for(int step=i+1; step<=i+nums[i]; step++) {
                if(step+nums[step] >= maxx) {
                    maxx = step+nums[step];
                    id = step;
                }
            }
            i = id;
            ans++;
        } 

        return ans;
    }
};