class Solution {
public:
    vector<string> ans;

    void solve(int n, string par, int abre, int fecha) {
        if (par.size() == 2*n-1) {
            par += ')';
            ans.push_back(par);
            return;
        } 
        if (abre != n) {
            solve(n, par+'(', abre+1, fecha);
        }
        if (fecha != n-1 && fecha != abre) {
            solve(n, par+')', abre, fecha+1);
        }
    }

    vector<string> generateParenthesis(int n) {
        solve(n, "(", 1, 0);
        return ans;
    }
};