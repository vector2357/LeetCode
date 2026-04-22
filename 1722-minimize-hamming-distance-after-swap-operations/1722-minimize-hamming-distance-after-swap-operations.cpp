class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        parent[find(a)] = find(b);
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        for (int i=0; i<allowedSwaps.size(); i++) {
            unite(allowedSwaps[i][0], allowedSwaps[i][1]);
        }

        unordered_map<int, unordered_map<int, int>> components;
        for (int i=0; i<n; i++) {
            components[find(i)][source[i]]++;
        }

        int ans = 0;
        for (int i=0; i<n; i++) {
            unordered_map<int, int>& freq = components[find(i)];
            if (freq.count(target[i]) && freq[target[i]] > 0) {
                freq[target[i]]--;
            }
            else {
                ans++;
            }
        }
        return ans;
    }
};