/*
1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.
Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        int infinite = 99999;
        vector<vector<int>> dist(n, vector<int>(n, infinite));
        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }

        for (auto it : edges)
        {
            int from = it[0];
            int to = it[1];
            int weight = it[2];
            dist[from][to] = dist[to][from] = weight;
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int mincount = n, city = -1;

        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] <= distanceThreshold)
                {
                    count++;
                }
            }

            if (count <= mincount)
            {
                mincount = count;
                city = i;
            }
        }

        return city;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> graph{
        {0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};

    cout << obj.findTheCity(4, graph, 4);
}