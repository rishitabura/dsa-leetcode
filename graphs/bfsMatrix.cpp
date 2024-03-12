#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    // using adjacency matrix

    int n, m;
    cout << "Enter the no of nodes and edges : ";
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>(n+1, 0));
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

    queue<int> q;
    vector<bool> visited(n + 1, false);
    int start = 1;
    q.push(start);
    visited[start] = true;
    cout << "Bfs traversal : "<< endl;
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        cout << a << " ";
        for (int i = 0; i <= n; i++)
        {
            if (adj[a][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    return 0;
}