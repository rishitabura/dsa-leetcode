/*tc - O(V*E)*/
class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int>dist(V, 1e8);
       
        int E = edges.size();
        dist[S] = 0;
        
        for(int i = 0; i<V-1; i++)
        {
            for(int j = 0; j<E; j++)
            {
                if(dist[edges[j][0]] != 1e8 && dist[edges[j][0]] + edges[j][2] < dist[edges[j][1]])
                {
                    dist[edges[j][1]] = dist[edges[j][0]] + edges[j][2];
                }
            }
        }
        
        // check for negetive cycle in nth iteration
        for(int j = 0; j<E; j++)
            {
                if(dist[edges[j][0]] != 1e8 && dist[edges[j][0]] + edges[j][2] < dist[edges[j][1]])
                {
                    return {-1};
                }
            }
        
        
        
        return dist;
        
    }
};