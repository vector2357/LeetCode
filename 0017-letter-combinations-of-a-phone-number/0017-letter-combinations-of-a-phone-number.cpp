class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> mp;
        mp['0'] = "";
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        int n= digits.size();
        vector<string> ans;

        if (digits.size() == 1) {
            for (int i=0; i<mp[digits[0]].size(); i++) {
                string s = "";
                s += mp[digits[0]][i];
                ans.push_back(s);
            }
        }
        else if (digits.size() == 2) {
            for (int i=0; i<mp[digits[0]].size(); i++) {
                for (int j=0; j<mp[digits[1]].size(); j++) {
                    string s = "";
                    s += mp[digits[0]][i];
                    s += mp[digits[1]][j];
                    ans.push_back(s);
                }
            }
        }
        else if (digits.size() == 3) {
            for (int i=0; i<mp[digits[0]].size(); i++) {
                for (int j=0; j<mp[digits[1]].size(); j++) {
                    for (int k=0; k<mp[digits[2]].size(); k++) {
                        string s = "";
                        s += mp[digits[0]][i];
                        s += mp[digits[1]][j];
                        s += mp[digits[2]][k];
                        ans.push_back(s);
                    }
                }
            }
        }
        else {
            for (int i=0; i<mp[digits[0]].size(); i++) {
                for (int j=0; j<mp[digits[1]].size(); j++) {
                    for (int k=0; k<mp[digits[2]].size(); k++) {
                        for (int l=0; l<mp[digits[3]].size(); l++) {
                            string s = "";
                            s += mp[digits[0]][i];
                            s += mp[digits[1]][j];
                            s += mp[digits[2]][k];
                            s += mp[digits[3]][l];
                            ans.push_back(s);
                        }
                    }
                }
            }
        }
        return ans;
    }
};