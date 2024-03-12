#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    // int n, m;
    // cout << "Enter the no of nodes and edges : ";
    // cin >> n >> m;

    // not weighted
    // vector<int> adj[n + 1];
    // cout << "Enter the u and v :" << endl;
    // for (int i = 0; i < m; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }
    // for (int u = 0; u <= n; u++)
    // {
    //     cout << u << " -> ";
    //     for (auto &i : adj[u])
    //     {
    //         cout << i << " ";
    //     }

    //     cout << endl;
    // }

    // // weighted graph
    // vector<pair<int, int>> adj[n + 1];
    // cout << "Enter the u, v and weight :" << endl;
    // for (int i = 0; i < m; i++)
    // {
    //     int u, v, wt;
    //     cin >> u >> v >> wt;
    //     adj[u].push_back(make_pair(v, wt));
    //     adj[v].push_back(make_pair(u, wt));
    // }
    // for (int u = 0; u <= n; u++)
    // {
    //     cout << u << " -> ";
    //     for (auto &i : adj[u])
    //     {
    //         cout << "(" << i.first << "," << i.second << ") ";
    //     }

    //     cout << endl;
    // }
    
    int n = 3;
    int m = 2;
    vector<vector<int>>edges = {{2,1}, {2,0}};

    vector < vector < int >> adj(n);

    // for(int i = 0; i<n; i++){
    //     adj[i].push_back(i);
    // }  
    
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

   for (int i = 0; i < n; i++) {
        cout << i << " ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}