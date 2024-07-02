class DisjointSet  {
     vector<int>rank, parent;
    public:
        DisjointSet(int n) {
            rank.resize(n+1, 0); 
            parent.resize(n+1);
            for(int i = 0;i<=n;i++) {
                parent[i] = i; 
            }
        }
        
        int findParent(int u)
        {
            if(u == parent[u])
            {
                return u;
            }
            return parent[u] = findParent(parent[u]);
        }
        
        void unionByRank(int u, int v)
        {
            int pu = findParent(u);
            int pv = findParent(v);
            
            if(rank[pu] < rank[pv])
            {
                parent[pu] = pv;
            }
            else if(rank[pu] > rank[pv])
            {
                parent[pv] = pu;
            }
            else
            {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int sum;
        vector<pair<int, pair<int,int>>> edges;
        // O(N + E)
        for(int i = 0; i<V; i++)
        {
            for(auto it: adj[i])
            {
                int node = i;
                int adjnode = it[0];
                int wt = it[1];
                
                edges.push_back({wt, {node, adjnode}});
            }
        }
        // O(E logE)
        sort(edges.begin(), edges.end());
        
        // O(E * 4 alpha*2)
        DisjointSet ds(V);
        for(auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findParent(u) != ds.findParent(v))
            {
                sum += wt;
                ds.unionByRank(u,v);
            }
        }
        return sum;
    }
};