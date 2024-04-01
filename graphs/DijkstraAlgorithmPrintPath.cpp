class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        vector<pair<int, int>> adj[n+1];
        for(auto it: edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
            
        }
        priority_queue<pair<int,int> , vector<pair<int, int>>, greater<pair<int, int>>> q;
        
        vector<int> dist(n+1, 1e9);
        vector<int>parent(n+1);
        for(int i = 1; i<=n; i++) parent[i] = i;
        
        
        q.push({0, 1});
        dist[1] = 0;
        
        while(!q.empty())
        {
            auto it = q.top();
            int dis = it.first;
            int node = it.second;
            q.pop();
            
            for(auto it: adj[node])
            {
                int edgewt = it.second;
                int adjnode = it.first;
                
                if(dist[adjnode] > dis + edgewt)
                {
                    dist[adjnode] = dis + edgewt;
                    q.push({dis + edgewt, adjnode});
                    parent[adjnode] = node;
                }
            }
        }
        
        if(dist[n] == 1e9) return {-1};
        
        vector<int>path;
        int end = n;
        while(parent[end] != end)
        {
            path.push_back(end);
            end = parent[end];
        }
        path.push_back(1);
        path.push_back(dist[n]);
        reverse(path.begin(), path.end());
        
        return path;
    }
};