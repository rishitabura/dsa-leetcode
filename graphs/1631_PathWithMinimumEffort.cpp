class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> q;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        dist[0][0] = 0;
        q.push({0, {0, 0}});

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto it = q.top();
            q.pop();

            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (r == n-1 && c == m-1)
                return diff;

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {

                    int neweffort = max(abs(heights[r][c] - heights[nr][nc]), diff);
                    
                    if(neweffort < dist[nr][nc])
                    {
                        dist[nr][nc] = neweffort;
                        q.push({neweffort, {nr, nc}});
                    } 
                }
            }
        }

        return 0;
    }
};