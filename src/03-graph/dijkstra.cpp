// Dado un grafo con pesos no negativos halla la ruta de costo minimo entre un nodo inicial u y todos los demas nodos.

struct edge {
    int v; int64 cost;
    bool operator < (const edge &other) const {
        return other.cost < cost;
    }
};

const int64 inf = 1e18;
const int N = 1e5+5; // Cantidad maxima de nodos
vector<edge> adj[N]; // Lista de adyacencia
bool was[N];         // Marca los nodos ya visitados
int64 dist[N];       // Almacena la distancia a cada nodo
int pre[N];          // Almacena el nodo anterior para construir las rutas
int n, m;            // Cantidad de nodos y aristas

void dijkstra(int u) {
    priority_queue<edge> Q;
    Q.push({u, 0});
    dist[u] = 0;
    
    while (!Q.empty()) {
        u = Q.top().v; Q.pop();
        if (!was[u]) {
            was[u] = true;
            for (auto &ed : adj[u]) {
                int v = ed.v;
                if (!was[v] && dist[v] > dist[u] + ed.cost) {
                    dist[v] = dist[u] + ed.cost;
                    pre[v] = u;
                    Q.push({v, dist[v]});
                }
            }
        }
    }
}

void init() {
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        was[i] = 0;
        dist[i] = inf;
    }
}