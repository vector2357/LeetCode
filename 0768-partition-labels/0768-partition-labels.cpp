class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        map<char, int> mp;

        for(int i=0; i<s.size(); i++) {
            mp[s[i]] = i;
        }
        int cont=0, maior=0;
        for(int i=0; i<s.size(); i++) {
            cont++;
            maior = max(maior, mp[s[i]]);
            if(maior == i) {
                ans.push_back(cont);
                cont = 0;
                maior = 0;
            }
        }
        return ans;
    }
};