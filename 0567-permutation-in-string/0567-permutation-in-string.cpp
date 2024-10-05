class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> mp, comp, aux;

        if(s1.size() > s2.size()) return false;

        for(int i=0; i<s1.size(); i++) {
            mp[s1[i]]++;
        }
        aux = mp;

        for(int i=0; i<=s2.size()-s1.size(); i++) {
            int j=i;
            while(j<s2.size() && aux[s2[j]] && j-i<s1.size()) {
                comp[s2[j]]++;
                j++;
            }
            if(mp == comp) return true;
            else comp.clear();
        }

        return false;
    }
};