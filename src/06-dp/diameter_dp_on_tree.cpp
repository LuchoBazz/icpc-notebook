const int mxN = 2e5 + 10;
vector<int> adj[mxN];
int n;
 
int dist[mxN];
int dp[mxN];
 
int dfs(int node, int parent) {
    dist[node] = 0;
    int mx_dist = 0;
    int first = -1, second = -1;
    for(auto &child: adj[node]) {
        if(child == parent)
            continue;
        mx_dist = max(mx_dist, dfs(child, node) + 1);
        if(dist[child] >= first) {
            if(first != -1) second = first;
            first = dist[child];
        } else if(dist[child] >= second) {
            second = dist[child];
        }
    }
    dist[node] = mx_dist;
    dp[node] = first + second + 2;
    return mx_dist;
}
// undigraph
// dfs(0, -1);
// int diameter = *max_element(dp, dp + n);