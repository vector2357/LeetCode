class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans = 0, i = cost.size()-1;
        sort(cost.begin(), cost.end());

        while (i>=0) {
            ans += cost[i];
            if (i-1 >= 0) ans += cost[i-1];
            i -= 3;
        }
        return ans;
    }
};