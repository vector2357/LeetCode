class Solution {
public:
    int myAtoi(string s) {
        int MAX = 2147483647;
        int MIN = -2147483648;
        int passo=1, sinal=1;
        long long ans=0;
        
        for(int i=0; i<s.size();) {
            while(i<s.size() && s[i] == ' ' && passo==1) {
                i++;
            }
            passo++;
            if(i<s.size() && s[i]=='-' && passo==2) {
                sinal*=-1;
                i++;
            }
            else {
                if(i<s.size() && s[i]=='+' && passo==2) i++;
            }
            passo++;
            if(i==s.size()) break;
            if(i<s.size() && (s[i]<'0' || s[i]>'9')) return (int)ans*sinal;
            ans*=10;
            ans+=(s[i]-48);
            if(sinal==-1) {
                if(ans*sinal <= MIN) return MIN;
            }
            else {
                if(ans >= MAX) return MAX;
            }
            i++;
        }
        return (int)ans*sinal;
    }
};