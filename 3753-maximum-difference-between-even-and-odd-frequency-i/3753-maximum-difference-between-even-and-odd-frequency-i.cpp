class Solution {
public:
    int maxDifference(string s) {
        map<char, int> mp;
        int impar = 1, par = 100;

        for(char c : s) {
            mp[c]++;
        }
        for(auto it : mp) {
            if((it.second)%2) {
                if(it.second > impar) {
                    impar = it.second;
                }
            }
            else {
                if(it.second < par) {
                    par = it.second;
                }
            }
        }
        return impar-par;
    }
};