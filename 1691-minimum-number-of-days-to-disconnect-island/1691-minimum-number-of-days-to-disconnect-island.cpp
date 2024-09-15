class Solution {
private:
    int vis;

public:
    bool verify(int i, int j, int row, int column) {
        return i>=0 && i<row && j>=0 && j<column;
    }

    int sizeIsland(vector<vector<int>>& grid) {
        int sum=0, row=grid.size(), column=grid[0].size();;
        for(int i=0; i<row; i++) {
            for(int j=0; j<column; j++) {
                sum+=grid[i][j];
            }
        }
        return sum;
    }

    void DFS(int i, int j, vector<vector<bool>>& adj, vector<vector<int>>& grid) {
        int x[] = {-1, 0, 1, 0};
        int y[] = {0, 1, 0, -1};

        vis++;
        adj[i][j] = true;

        for(int k=0; k<4; k++) {
            int ii = i+x[k], jj = j+y[k];
            bool ver=verify(ii, jj, grid.size(), grid[0].size());
            if(ver && grid[ii][jj]==1 && adj[ii][jj]==false) {
                DFS(ii, jj, adj, grid);
            }
        }
    }

    int minDays(vector<vector<int>>& grid) {
        int row=grid.size(), column=grid[0].size(), sum=sizeIsland(grid), I, J;
        bool first=true;
        pair<int, int> aux;

        vector<vector<bool>> adj;

        if(!sum) return 0;

        for(int i=0; i<row; i++) {
            for(int j=0; j<column; j++) {
                if(grid[i][j]==1) {
                    adj.assign(300, vector<bool>(300, false));
                    vis=0;
                    DFS(i, j, adj, grid);
                    if(first) {
                        if(sum!=vis) return 0;
                        first=false;
                        grid[i][j]=0;
                        aux = {i, j};
                        I=i, J=j;
                    }
                    else {
                        if(sum-1!=vis) return 1;
                        grid[aux.first][aux.second]=1;
                        grid[i][j]=0;
                        aux = {i, j};
                    }
                }
            }
        }
        adj.assign(300, vector<bool>(300, false));
        vis=0;
        DFS(I, J, adj, grid);

        if(sum-1!=vis) return 1;
        return 2;
    }
};