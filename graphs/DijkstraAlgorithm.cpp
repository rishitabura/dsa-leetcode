/*using priority queue
tc - */
class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int> , vector<pair<int, int>>, greater<pair<int, int>>> q;
        
        vector<int> dist(V, 1e9);
        q.push({0, S});
        dist[S] = 0;
        
        while(!q.empty())
        {
            int dis = q.top().first;
            int node = q.top().second;
            q.pop();
            
            for(auto it: adj[node])
            {
                int edgewt = it[1];
                int adjnode = it[0];
                
                if(dist[adjnode] > dis + edgewt)
                {
                    dist[adjnode] = dis + edgewt;
                    q.push({dist[adjnode], adjnode});
                }
            }
        }
        return dist;
    }
};

/*using set*/
class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> st;
        vector<int> dist(V, INT_MAX);
    
        st.insert({0, S});
        dist[S] = 0;
    
        while(!st.empty())
        {
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);
    
            for(auto it: adj[node])
            {
                int edgewt = it[1];
                int adjnode = it[0];
    
                if(dist[adjnode] > dis + edgewt)
                {
                    if(dist[adjnode] != INT_MAX)
                    {
                        st.erase({dist[adjnode], adjnode});
                    }
    
                    dist[adjnode] = dis + edgewt;
                    st.insert({dist[adjnode], adjnode});
                }
            }
        }
        return dist;
        
    }
};
