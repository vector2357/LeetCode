class Solution {
public:
    static bool func(vector<int> A, vector<int> B) {
        if (A[1]-A[0] != B[1]-B[0]) {
            return A[1]-A[0] < B[1]-B[0];
        }
        return A[0] < B[0];
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), func);

        int ans = tasks[0][1];

        for (int i=1; i<tasks.size(); i++) {
            ans = max(ans+tasks[i][0], tasks[i][1]);
        }
        return ans;
    }
};