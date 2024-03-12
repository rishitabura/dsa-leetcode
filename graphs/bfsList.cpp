#include <bits/stdc++.h>
#include <vector>
using namespace std;

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
        for (auto &i : adj[a])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }

 
    return 0;
}