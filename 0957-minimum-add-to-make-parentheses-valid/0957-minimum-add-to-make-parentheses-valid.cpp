class Solution {
public:
    int minAddToMakeValid(string s) {
        int aberto=0, ans=0;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') {
                aberto++;
            }
            else {
                if(!aberto) {
                    ans++;
                }
                else {
                    aberto--;
                }
            }
        }

        return ans+aberto;
    }
};