class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;

        for (int i=0; i<s.size(); i++) {
            if (s[i] != ' ') {
                if (i==0 || s[i-1] == ' ') {
                    ans = 1;
                }
                else {
                    ans++;
                }
            }
        }
        return ans;
    }
};