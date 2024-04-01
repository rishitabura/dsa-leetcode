/*using toposort 
tc- O(N+M)*/
class Solution {
  private:
    void toposort(int node,  vector<int> &vis, stack<int> &st, vector<pair<int, int>>adj[]){
        
        vis[node] = 1;
        for(auto it : adj[node])
        {
            int v = it.first;
            if(!vis[v])
            {
                toposort(v, vis, st,adj);
            }
        }
        st.push(node);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        vector<pair<int, int>> adj[N];
        for(int i = 0; i<M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        stack<int>st;
        vector<int>vis(N,0);
        for(int i = 0;i<N; i++)
        {
            if(!vis[i])
            {
                toposort(i, vis, st, adj);
            }
        }
        
        vector<int> dist(N, 1e9);
        dist[0]  = 0;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            // O(N+M)
            for(auto it: adj[node])
            {
                int v = it.first;
                int wt = it.second;
                
                if(dist[node] + wt < dist[v])
                {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        for(int i = 0; i<dist.size(); i++)
        {
            if(dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};