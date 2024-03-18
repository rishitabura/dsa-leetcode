class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m,0));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        for(int i = 0;i<n;i++) {
	        for(int j = 0;j<m;j++) {
	            if(mat[i][j] == 0) {
	                q.push({{i,j}, 0}); 
	                vis[i][j] = 1; 
	            }
	            else {
	                vis[i][j] = 0; 
	            }
	        }
	    }
        
      
        int dx[] = {-1, 0, +1, 0}; 
	    int dy[] = {0, +1, 0, -1}; 
        
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[r][c] = steps;            
            for(int i = 0; i<4; i++)
            {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr>=0 && nr<n && nc>=0 && nc < m && !vis[nr][nc])
                {
                    vis[nr][nc] = 1;
                    q.push({{nr,nc}, steps+1});
                }
            }
        }

        return dist;
    }
};