#include <bits/stdc++.h>
#include <vector>
using namespace std;

void dfs(int node, vector<bool> &visited, vector<int> adj[])
{
    visited[node] = true;
    cout << node << " ";

    for (auto &it : adj[node])
    {
        if (!visited[it])
        {
            dfs(it, visited, adj);
        }
        
    }
    
}
int main()
{
    int n, m;
    cout << "Enter the no of nodes and edges : ";
    cin >> n >> m;

    vector<int> adj[n + 1];
    cout << "Enter the u and v :" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "Adjacency list\n";
    for (int u = 0; u <= n; u++)
    {
        cout << u << " -> ";
        for (auto &i : adj[u])
        {
            cout << i << " ";
        }

        cout << endl;
    }
    int start = 1;
    vector<bool> visited(n + 1, false);

    dfs(start, visited, adj);
    return 0;
}