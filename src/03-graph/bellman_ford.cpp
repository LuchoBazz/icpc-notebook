struct edge {
    int from, to;
    int64 cost;
};

int n, m;
const int N = 2505;
const int64 inf = 1e18;
vector<edge> edges;

vector<int64> bellman_ford(int u, bool &cycle) {
    vector<int64> dist(n, inf);
    dist[u] = 0LL;
    for(int i = 0; i < n + 1; ++i){
        for(const edge &e: edges) {
            if(dist[e.from] != inf && dist[e.from] + e.cost < dist[e.to]) {
                dist[e.to] = dist[e.from] + e.cost;
                if(i == n)
                    cycle = true; // There are negative edges
            }
        }
    }
    return dist;
    // Time Complexity: O(V*E), Space Complexity: O(V)
}