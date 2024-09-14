class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i, j, maior=0, aux;
        set<char> st;
        
        for(i=0; i<s.size(); i++)
        {
            st.clear();
            for(j=i; j<s.size(); j++)
            {
                aux=st.size();
                st.insert(s[j]);
                if(st.size()==aux) break;
            }
            if(st.size()>maior) maior=st.size();
        }
        return maior;
    }
};