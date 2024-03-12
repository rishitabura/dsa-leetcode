/*tc - O(n*m) + O(n*m*4) ~ O(n*m)
sc - O(n*m) */
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int vis[n][m];
        // {{r,c}, t}
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }
            }
        }

        int time = 0;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);
            for (int i = 0; i < 4; i++) {
                int nrow = r + dx[i];
                int ncol = c + dy[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                }
            }
        }

        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(vis[i][j] != 2 && grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return time;
    }
};

// without traversing at last
// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {

//         int n = grid.size();
//         int m = grid[0].size();

//         int vis[n][m];
//         // {{r,c}, t}
//         int countFresh = 0;
//         queue<pair<pair<int, int>, int>> q;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (grid[i][j] == 2) {
//                     q.push({{i, j}, 0});
//                     vis[i][j] = 2;
//                 } else {
//                     vis[i][j] = 0;
//                 }

//                 if(grid[i][j] == 1) countFresh++;
//             }
//         }

//         int time = 0;
//         int dx[] = {-1, 0, 1, 0};
//         int dy[] = {0, 1, 0, -1};
//         int cnt = 0;
//         while (!q.empty()) {
//             int r = q.front().first.first;
//             int c = q.front().first.second;
//             int t = q.front().second;
//             q.pop();
//             time = max(time, t);
//             for (int i = 0; i < 4; i++) {
//                 int nrow = r + dx[i];
//                 int ncol = c + dy[i];

//                 if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
//                     grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2) {
//                     q.push({{nrow, ncol}, t + 1});
//                     vis[nrow][ncol] = 2;
//                     cnt++;
//                 }
//             }
//         }

//         // for(int i = 0; i<n; i++)
//         // {
//         //     for(int j = 0; j<m; j++)
//         //     {
//         //         if(vis[i][j] != 2 && grid[i][j] == 1)
//         //         {
//         //             return -1;
//         //         }
//         //     }
//         // }
//         if(cnt != countFresh)
//         {
//             return -1;
//         }

//         return time;
//     }
// };