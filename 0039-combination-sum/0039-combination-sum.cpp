class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> st;

    void getComb(int idx, int target, int sum, stack<int>& s, vector<int>& candidates) {
        if(sum > target) return;
        if(sum == target) {
            vector<int> v;
            while(s.size()) {
                v.push_back(s.top());
                s.pop();
            }
            for(int i=v.size()-1; i>=0; i--) s.push(v[i]);
            st.insert(v);
            
            return;
        }
        if(idx == candidates.size()) return;
        s.push(candidates[idx]);
        getComb(idx, target, sum+candidates[idx], s, candidates);
        getComb(idx+1, target, sum+candidates[idx], s, candidates);
        s.pop();
        getComb(idx+1, target, sum, s, candidates);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        stack<int> s;
        getComb(0, target, 0, s, candidates);

        for(auto it : st) {
            ans.push_back(it);
        }
        return ans;
    }
};