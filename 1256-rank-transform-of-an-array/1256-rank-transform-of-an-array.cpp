class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans, aux;
        aux = arr;
        sort(aux.begin(), aux.end());
        map<int, int> mp;

        for(int i=0, cont=1; i<aux.size(); i++) {
            if(mp[aux[i]] == 0) {
                mp[aux[i]] = cont;
                cont++;
            }
        }
        for(int i=0; i<arr.size(); i++) {
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};