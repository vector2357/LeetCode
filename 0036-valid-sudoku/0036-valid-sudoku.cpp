class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> s;
        cout << "1\n";
        for(int i=0; i<9; i++) {
            s.clear();
            for(int j=0; j<9; j++) {
                if(board[i][j] != '.') {
                    if(s.count(board[i][j])) return false;
                    s.insert(board[i][j]);
                }
            }
        }
        cout << "1\n";
        for(int j=0; j<9; j++) {
            s.clear();
            for(int i=0; i<9; i++) {
                if(board[i][j] != '.') {
                    if(s.count(board[i][j])) return false;
                    s.insert(board[i][j]);
                }
            }
        }
        cout << "1\n";
        for(int k=0; k<9; k++) {
            s.clear();
            int ini_I = k/3*3, ini_J = k%3*3;
            for(int i=ini_I; i<ini_I+3; i++) {
                for(int j=ini_J; j<ini_J+3; j++) {
                    if(board[i][j] != '.') {
                        if(s.count(board[i][j])) return false;
                        s.insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }
};