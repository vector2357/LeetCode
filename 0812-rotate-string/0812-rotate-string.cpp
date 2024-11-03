class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        if(s == goal) return true;

        queue<char> q, g;

        for(int i=0; i<s.size(); i++) {
            q.push(s[i]);
            g.push(goal[i]);
        }
        for(int i=0; i<s.size(); i++) {
            q.push(q.front());
            q.pop();

            if(q == g) return true;
        }
        return false;
    }
};