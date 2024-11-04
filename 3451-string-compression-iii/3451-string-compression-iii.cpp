class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int cont = 1, i;

        for(i=1; i<word.size(); i++) {
            if(word[i] == word[i-1] && cont<9) {
                cont++;
            }
            else {
                comp += cont+48;
                comp += word[i-1];
                cont = 1;
            }
        }
        comp += cont+48;
        comp += word[i-1];

        return comp;
    }
};