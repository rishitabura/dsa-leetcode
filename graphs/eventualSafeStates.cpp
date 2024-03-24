/* tc - O(V+E)
sc- O(n) + O(n) + O(n)*/
class Solution {
  private:
    bool dfs(int node,vector<int> adj[],  vector<int>&vis,  vector<int>&pathvis, 
    vector<int>&check)
    {
        vis[node] = 1;
        pathvis[node] = 1;
        
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it, adj, vis, pathvis, check) == true)
                {
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathvis[it] == 1)
            {
                check[node] = 0;
                return true;
            }
        }
        
        pathvis[node] = 0;
        check[node] = 1;
        return false;
        
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        
        vector<int>vis(V, 0);
        vector<int>pathvis(V, 0);
        vector<int>check(V, 0);
        vector<int>safeNode;
        
        for(int i = 0; i<V; i++)
        {
            if(!vis[i])
            {
                dfs(i, adj, vis, pathvis, check);
            }
        }
        
        for(int i = 0; i<V; i++)
        {
            if(check[i] == 1)
            {
                safeNode.push_back(i);
            }
        }
        
        return safeNode;
    }
};