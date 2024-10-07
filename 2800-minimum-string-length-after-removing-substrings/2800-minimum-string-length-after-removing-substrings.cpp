class Solution {
public:
    int minLength(string s) {
        stack<char> p;
        for(int i=0; i<s.size(); i++) {
            if(p.empty()) {
                p.push(s[i]);
            }
            else {
                if((p.top()=='A' && s[i]=='B') || (p.top()=='C' && s[i]=='D')) {
                    p.pop();
                }
                else {
                    p.push(s[i]);
                }
            }
        }

        return p.size();
    }
};