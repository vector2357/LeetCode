class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str;
        int minn=300, id, i, j;

        for(i=0; i<strs.size(); i++) {
            if(strs[i].size() < minn) {
                minn = strs[i].size();
                id = i;
            }
        }
        for(j=0; j<strs[id].size(); j++) {
            char aux = strs[0][j];
            for(i=1; i<strs.size() && strs[i][j]==aux; i++);
            if(i==strs.size()) str.push_back(aux);
            else break;
        }

        return str;
    }
};