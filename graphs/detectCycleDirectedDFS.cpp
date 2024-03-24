class Solution {
  private:
    bool dfs(int node, vector<int> adj[], vector<int>&vis,  vector<int>&path){
        
        vis[node] = 1;
        path[node] = 1;
        
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it, adj, vis, path) == true)
                {
                    return true;
                }
                
            }
            else if(vis[it] == 1 && path[it] == 1)
            {
                return true;
            }
        }
        
        path[node] = 0;
        
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<int>vis(V, 0);
        vector<int>path(V, 0);
        
        for(int i = 0; i<V; i++)
        {
            if(!vis[i])
            {
                if(dfs(i, adj, vis, path) == true)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};