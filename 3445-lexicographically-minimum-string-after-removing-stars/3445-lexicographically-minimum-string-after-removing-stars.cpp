class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;

        set<int> positions;
        string ans = "";

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '*') {
                positions.insert(i);
                positions.insert(pq.top().second * (-1));
                pq.pop();
            }
            else {
                pq.push({s[i], -i});
            }
        }
        for(int i=0; i<s.size(); i++) {
            if(positions.find(i) == positions.end()) {
                ans += s[i];
            }
        }
        return ans;
    }
};