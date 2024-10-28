class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int sum=0;
        pair<int, int> mat[matrix.size()][matrix[0].size()];

        for(int i=0; i<matrix.size(); i++) {
            mat[i][0].first = matrix[i][0];
            for(int j=1; j<matrix[0].size(); j++) {
                if(matrix[i][j])
                    mat[i][j].first = matrix[i][j]+mat[i][j-1].first;
                else
                    mat[i][j].first = 0; 
            }
        }
        for(int j=0; j<matrix[0].size(); j++) {
            mat[0][j].second = matrix[0][j];
            for(int i=1; i<matrix.size(); i++) {
                if(matrix[i][j])
                    mat[i][j].second = matrix[i][j]+mat[i-1][j].second;
                else
                    mat[i][j].second = 0;
            }
        }

        for(int i=matrix.size()-1; i>=0; i--) {
            for(int j=matrix[0].size()-1; j>=0; j--) {
                int row = mat[i][j].first;
                int col = mat[i][j].second;
                int val = min(row, col), x = i, y = j;

                while(matrix[x][j] && matrix[i][y] && row>(i-x) && col>(j-y)) {
                    x--;
                    y--;
                    sum++;
                    if(x<0 || y<0) break;
                    row = mat[x][j].first;
                    col = mat[i][y].second;
                }
            }
        }

        return sum;
    }
};