/*using dfs
tc - O(V+2E) + O(n)*/
class Solution
{
private:
    bool dfs(int node, int parent, vector<int> adj[], int vis[])
    {
        vis[node] = 1;
        for (auto adjnode : adj[node])
        {
            if (!vis[adjnode])
            {
                if (dfs(adjnode, node, adj, vis) == true)
                {
                    return true;
                }
            }
            else if (adjnode != parent)
            {
                return true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, -1, adj, vis) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};