class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        int n = sentence1.size(), m = sentence2.size(), i, j;
        if(n < m) {
            swap(sentence1, sentence2);
            swap(n, m);
        }
        vector<string> vet1, vet2;
        vet1.push_back("");
        vet2.push_back("");

        for(i=0; i<n; i++) {
            if(sentence1[i] != ' ') {
                vet1[vet1.size()-1]+=sentence1[i];
            }
            else {
                vet1.push_back("");
            }
        }
        for(i=0; i<m; i++) {
            if(sentence2[i] != ' ') {
                vet2[vet2.size()-1]+=sentence2[i];
            }
            else {
                vet2.push_back("");
            }
        }

        int l=0, r=vet1.size()-1;

        if(vet2.size() == 1) {
            if(vet1[l]==vet2[0] || vet1[r]==vet2[0])
                return true;
            return false;
        }

        for(i=0, j=vet2.size()-1; i<=j;) {
            if(vet1[l]!=vet2[i] && vet1[r]!=vet2[j])
                return false;
            if(vet1[l]==vet2[i]) {
                i++;
                l++;
            }
            if(vet1[r]==vet2[j]) {
                j--;
                r--;
            }
        }

        return true;
    }
};