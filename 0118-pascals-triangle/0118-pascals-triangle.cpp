class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        v.assign(numRows, vector<int>());
        v[0].push_back(1);

        for(int i=1; i<numRows; i++) {
            for(int j=0; j<=i; j++) {
                if(j==0 || j==i) {
                    v[i].push_back(1);
                }
                else {
                    v[i].push_back(v[i-1][j-1] + v[i-1][j]);
                }
            }
        }

        return v;
    }
};