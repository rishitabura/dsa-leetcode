class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, pair<int, int> >> q;
        vector<vector<int>> dist (n, vector<int>(m, INT_MAX));
        pair<int, int> src = {0,0};
        pair<int, int> dest = {n-1, n-1};

        if(grid[0][0] == 1) return -1;
        if(grid[n-1][m-1] == 1) return -1;
        if(n == 1 && grid[0][0] == 0) return 1;

        dist[0][0] = 1;
        q.push({1, {0,0}});

        int dx[] = {-1,0,1,0, 1,-1,-1,1};
        int dy[] = {0,1,0,-1, 1,1,-1,-1};

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for(int i = 0; i<8; i++)
            {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0 && dis+1 < dist[nr][nc])
                {
                    dist[nr][nc] = dis + 1;
                    if(nr == dest.first && nc == dest.second) return dis+1;
                    q.push({dis+1, {nr,nc}});
                }
            }
        }

        return -1;
    }
};