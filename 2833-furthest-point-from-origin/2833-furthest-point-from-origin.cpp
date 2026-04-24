class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int ans=0, diff=0;

        for (char c : moves) {
            if (c == 'L') diff--;
            else if (c == 'R') diff++;
            else ans++;
        }
        return ans + abs(diff);
    }
};