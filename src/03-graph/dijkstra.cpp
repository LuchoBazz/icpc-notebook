// Dado un grafo con pesos no negativos halla la ruta de costo minimo entre un nodo inicial u y todos los demas nodos.

struct edge {
    int v; int64 w;
    bool operator < (const edge &o) const {
        return o.w < w; // invertidos para que la pq ordene de < a >
    }
};

const int64 inf = 1e18;
const int MX = 1e5+5; // Cantidad maxima de nodos
vector<edge> g[MX]; // Lista de adyacencia
vector<bool> was; // Marca los nodos ya visitados
vector<int64> dist; // Almacena la distancia a cada nodo
int pre[MX]; // Almacena el nodo anterior para construir las rutas
int n, m; // Cantidad de nodos y aristas

void dijkstra(int u) {
    priority_queue<edge> Q;
    Q.push({u, 0});
    dist[u] = 0;
    
    while (Q.size()) {
        u = Q.top().v; Q.pop();
        if (!was[u]) {
            was[u] = true;
            for (auto &ed : g[u]) {
                int v = ed.v;
                if (!was[v] && dist[v] > dist[u] + ed.w) {
                    dist[v] = dist[u] + ed.w;
                    pre[v] = u;
                    Q.push({v, dist[v]});
                }
            }
        }
    }
}

void init() {
    was.assign(n, false);
    dist.assign(n, inf);
    for (int i = 0; i <= n; i++)
        g[i].clear();
}