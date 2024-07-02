// tc - O(4 aplha) constant
// sc- O(N)
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n+1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int u)
    {
        if (u == parent[u])
        {
            return u;
        }
        return parent[u] = findParent(parent[u]);
    }

    void unionByRank(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv)
            return;
        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};