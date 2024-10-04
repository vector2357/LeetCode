class Solution {
public:
    void recursive(int n) {

    }

    string countAndSay(int n) {
        if(n == 1) return "1";

        string aux="", str = countAndSay(n-1);
        int cont=1;

        for(int i=1; i<str.size(); i++) {
            if(str[i] != str[i-1]) {
                aux+=(cont+48);
                aux+=str[i-1];
                cont=1;
            }
            else {
                cont++;
            }
        }
        aux+=(cont+48);
        aux+=str[str.size()-1];

        return aux;
    }
};