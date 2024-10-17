class Solution {
public:
    int maximumSwap(int num) {
        int ans=0, temp=num;
        vector<int> v;
        while(temp) {
            v.push_back(temp%10);
            temp/=10;
        }
        int n = v.size(), maxx, id;

        for(int i=n-1; i>=0; i--) {
            maxx=0;
            id=0;
            for(int j=0; j<i; j++) {
                if(v[j]>maxx) {
                    maxx = v[j];
                    id = j;
                }
            }
            if(maxx>v[i]) {
                swap(v[id], v[i]);
                for(int k=0; k<n; k++) {
                    ans+=v[k]*pow(10, k);
                }
                return ans;
            }
        }
        return num;
    }
};