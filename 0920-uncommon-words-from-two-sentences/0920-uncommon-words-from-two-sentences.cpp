class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> vet;
        unordered_map<string, int> mp;
        unordered_map<string, int>::iterator it;
        string aux = "";

        for(int i=0; i<s1.size(); i++) {
            if(s1[i] != ' ') {
                aux += s1[i];
            }
            else {
                mp[aux]++;
                aux = "";
            }
        }
        mp[aux]++;
        aux = "";

        for(int i=0; i<s2.size(); i++) {
            if(s2[i] != ' ') {
                aux += s2[i];
            }
            else {
                mp[aux]++;
                aux = "";
            }
        }
        mp[aux]++;

        for(it=mp.begin(); it!=mp.end(); it++) {
            if(it->second == 1) {
                vet.push_back(it->first);
            }
        }

        return vet;
    }
};