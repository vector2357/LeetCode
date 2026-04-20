class Solution {
public:
    vector<vector<pair<int, char>>> adj;
    vector<vector<int>> dp;
    set<int> estadosFinais;

    bool dfs(int q, int idx, string s) {
        if (idx == s.size()) {
            return (estadosFinais.find(q) != estadosFinais.end());
        }
        if (dp[q][idx] != -1) return dp[q][idx];

        for (auto v : adj[q]) {
            if (v.second == ' ') {
                if (dfs(v.first, idx, s)) {
                    return true;
                }
            }
            else {
                if (s[idx] == v.second || v.second == '.') {
                    if (dfs(v.first, idx+1, s)) {
                        return true;
                    }
                }
            }
        }
        dp[q][idx] = 0;
        return false;
    }

    bool isMatch(string s, string p) {
        int n = p.size();

        adj.resize(n+1);
        dp.assign(n+1, vector<int>(s.size(), -1));

        int ultimoEstado = 0;
        for (int i=0; i<n; i++) {
            if (i == 0) {
                estadosFinais.insert(0);
                if (i+1<n && p[i+1]=='*') {
                    estadosFinais.insert(n);
                    adj[n].push_back({ i, ' ' });
                }
                else {
                    adj[n].push_back({ i, p[i] });
                }
                continue;
            }
            if (p[i] == '*') {
                adj[i-1].push_back({ i-1, p[i-1] });
            }
            else {
                if (i+1<n && p[i+1]=='*') {
                    adj[ultimoEstado].push_back({ i, ' ' });
                }
                else {
                    estadosFinais.clear();
                    adj[ultimoEstado].push_back({ i, p[i] });
                }
                estadosFinais.insert(i);
                ultimoEstado = i;
            }
        }

        return dfs(n, 0, s);
    }
};