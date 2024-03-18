class Solution {
private:
    void bfs(vector<int>& vis, vector<vector<int>>& rooms) {
        queue<int> q;
        int n = rooms.size();
        vis[0] = 1;
        for (int i = 0; i < rooms[0].size(); i++) {
            q.push(rooms[0][i]);
            vis[rooms[0][i]] = 1;
        }

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int r = q.front();
                q.pop();
                int s = rooms[r].size();
                for (int j = 0; j < s; j++) {
                    if (!vis[rooms[r][j]]) {
                        int temp = rooms[r][j];
                        q.push(temp);
                        vis[temp] = 1;
                    }
                }
            }
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();
        vector<int> vis(n, 0);
        bfs(vis, rooms);
        for (int i = 0; i < n; i++) {
            cout << vis[i] << endl;
        }
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                return false;
            }
        }
        return true;
    }
};