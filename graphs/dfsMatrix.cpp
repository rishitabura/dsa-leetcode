#include <bits/stdc++.h>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<bool> visited(n + 1, false);
void dfs(int start, vector<vector<int>> &adj, int n)
{
    cout << start << " ";
    visited[start] = true;

    for (int i = 0; i <= n; i++)
    {
        if (adj[start][i] == 1 && !visited[i])
        {
            dfs(i, adj, n);
        }
    }
}

int main()
{
    // using adjacency matrix

    int m;
    cout << "Enter the no of nodes and edges : ";
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    cout << "Enter the u and v :" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1; // for undirected

        // adj[u][v] = 1;      //for directed
    }
    cout << "Adjacency matrix\n";
    for (int u = 1; u <= n; u++)
    {
        for (int v = 1; v <= n; v++)
        {
            cout << adj[u][v] << " ";
        }
        cout << endl;
    }
    cout << "Dfs traversal : " << endl;
    dfs(1, adj, n);
    return 0;
}