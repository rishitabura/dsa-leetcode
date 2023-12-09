/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        int infinite = 99999;
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, infinite));

        for (int i = 1; i <= n; i++)
        {
            dist[i][i] = 0;
        }

        for (auto it : times)
        {
            int from = it[0];
            int to = it[1];
            int time = it[2];
            dist[from][to] = time;
        }

        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][j] == infinite)
                {
                    cout << "Infi"
                         << "\t";
                }
                else
                {
                    cout << dist[i][j] << "\t";
                }
            }
            cout << endl;
        }

        int ans = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, dist[k][i]);
        }
        return ans != infinite ? ans : -1;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> time{
        {2, 1, 1}, {2, 3, 1}, {3, 4, 1}};

    cout << obj.networkDelayTime(time, 4, 2);
}