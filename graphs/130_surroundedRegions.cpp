/*using dfs*/
class Solution {
private:
    void dfs(int r, int c, vector<vector<char>>& board,
             vector<vector<int>>& vis) {
        vis[r][c] = 1;
        int n = board.size();
        int m = board[0].size();
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                board[nr][nc] == 'O' && !vis[nr][nc]) {
                dfs(nr, nc, board, vis);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                // vis[i][0] = 1;
                dfs(i, 0, board, vis);
            }
        }

        for (int i = 0; i < n; i++) {
            if (board[i][m - 1] == 'O' && !vis[i][m - 1]) {
                // vis[i][0] = 1;
                dfs(i, m - 1, board, vis);
            }
        }

        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O' && !vis[0][i]) {
                // vis[i][0] = 1;
                dfs(0, i, board, vis);
            }
        }

        for (int i = 0; i < m; i++) {
            if (board[n - 1][i] == 'O' && !vis[n - 1][i]) {
                // vis[i][0] = 1;
                dfs(n - 1, i, board, vis);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && vis[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};