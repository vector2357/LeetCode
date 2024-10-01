class Solution {
public:
    string convert(string s, int numRows) {    
        if(numRows == 1) return s;
        
        vector<string> str;
        str.assign(numRows, "");

        for(int i=0, j=0, inc=-1; i<s.size(); i++) {
            if(j==0 || j==numRows-1) inc*=-1;

            str[j]+=s[i];

            j+=inc;
        }

        string ans="";
        for(int i=0; i<numRows; i++) {
            ans+=str[i];
        }

        return ans;
    }
};