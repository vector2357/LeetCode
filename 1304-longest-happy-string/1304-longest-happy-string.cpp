class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a) pq.push({a, 'a'});
        if(b) pq.push({b, 'b'});
        if(c) pq.push({c, 'c'});

        string str="";
        int cont_letter=0;

        while(!pq.empty()) {
            pair<int, char> temp = {-1, 'z'};
            if(str.size() && str[str.size()-1] == pq.top().second && cont_letter==2) {
                temp = pq.top();
                pq.pop();
                if(pq.empty()) break;
                cont_letter=0;
            }
            int cont = pq.top().first;
            char cc = pq.top().second;
            pq.pop();

            if(str.size() && cc == str[str.size()-1]) cont_letter=2;
            str+=cc;
            cont--;

            if(cont) pq.push({cont, cc});
            if(temp.first != -1) pq.push(temp);
        }
        return str;
    }
};