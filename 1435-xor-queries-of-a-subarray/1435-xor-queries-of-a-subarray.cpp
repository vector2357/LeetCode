class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> v;
        for(int i=0; i<queries.size(); i++) {
            int aux = arr[queries[i][0]];
            int pos1 = queries[i][0]+1, pos2 = queries[i][1];
            while(pos1 <= pos2) {
                aux = aux ^ arr[pos1];
                pos1++;
            }
            v.push_back(aux);
        }

        return v;
    }
};