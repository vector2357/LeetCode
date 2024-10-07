class Solution {
public:
    string longestPalindrome(string s) {
        string str="";
        str+=s[0];
        int ans=1;
        
        for(int i=1; i<s.size(); i++) {
            int cont=0, x=i-1, y=i;
            
            while(x>=0 && y<s.size() && s[x]==s[y]) {
                cont+=2;
                x--;
                y++;
            }
            if(cont > ans) {
                ans = cont;
                str = "";
                str.append(s, x+1, y-(x+1));
            }
            
            x=i-1;
            y=i+1;
            cont=1;
            
            while(x>=0 && y<s.size() && s[x]==s[y]) {
                cont+=2;
                x--;
                y++;
            }
            if(cont > ans) {
                ans = cont;
                str = "";
                str.append(s, x+1, y-(x+1));
            }
        }
        
        return str;
    }
};