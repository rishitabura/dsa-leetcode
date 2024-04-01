class Solution {
private:
    void dfs(int row, int col,vector<vector<int>>& visited, vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nr = row + dx[k];
            int nc = col + dy[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                grid[nr][nc] == '1' && visited[nr][nc] == 0) {
                dfs(nr, nc, visited, grid);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    dfs(i, j, visited, grid);
                }
            }
        }

        return count;
    }
};