#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter the no of nodes and edges : ";
    cin >> n >> m;
    int adj[n + 1][n + 1] = {0};
    cout << "Enter the u and v :" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;      //for undirected
        
        // adj[u][v] = 1;      //for directed

    }
    for (int u =1; u <=n; u++)
    {
        for (int v = 1; v <=n; v++)
        {
            cout << adj[u][v] << " ";
        }
        cout << endl;
    }
    return 0;
}