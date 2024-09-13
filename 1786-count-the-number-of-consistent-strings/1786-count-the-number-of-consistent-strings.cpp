class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> s1, s2;
        int cont=0;

        for(int i=0; i<allowed.size(); i++) {
            s1.insert(allowed[i]);
        }

        for(int i=0; i<words.size(); i++) {
            s2 = s1;
            for(int j=0; j<words[i].size(); j++) {
                s2.insert(words[i][j]);
            }
            if(s1 == s2) cont++;
        }

        return cont;
    }
};