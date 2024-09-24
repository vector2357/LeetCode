class Solution {
public:
    int reverse(int x) {
        if(!x) return 0;

        long control = pow(2, 31);
        long ans=0;
        int sinal=1;
        long temp = x;
        if(x < 0) {
            sinal*=-1;
            temp*=-1;
        }
        int aux = floor(log10(temp));

        while(temp > 0) {
            ans+=pow(10, aux) * (temp%10);
            temp/=10;
            aux--;
        }
        if(ans > control) return 0;
        ans*=sinal;

        return (int)ans;
    }
};