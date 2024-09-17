class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> ai, bi;
        ai.assign(n+1, 0);
        bi.assign(n+1, 0);

        for(int i=0; i<trust.size(); i++) {
            ai[trust[i][0]]++;
            bi[trust[i][1]]++;
        }
        for(int i=1; i<=n; i++) {
            if(ai[i] == 0 && bi[i] == n-1) return i;
        }
        return -1;
    }
};