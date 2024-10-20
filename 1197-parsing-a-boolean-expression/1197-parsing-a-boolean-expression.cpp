class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> p;
        
        for(int i=0; i<expression.size(); i++) {
            if(expression[i]=='&' || expression[i]=='|' || expression[i]=='!' || expression[i]=='f' || expression[i]=='t') {
                p.push(expression[i]);
            }
            else if(expression[i] == ')') {
                bool hasTrue=false, hasFalse=false;

                while(p.top()=='f' || p.top()=='t') {
                    if(p.top() == 'f') hasFalse = true;
                    if(p.top() == 't') hasTrue = true;
                    p.pop();
                }
                char opr = p.top();
                p.pop();

                if(opr == '&') {
                    p.push((hasFalse) ? 'f' : 't');
                }
                else if(opr == '|') {
                    p.push((hasTrue) ? 't' : 'f');
                }
                else {
                    p.push((hasTrue) ? 'f' : 't');
                }
            }
        }

        return p.top() == 't';
    }
};