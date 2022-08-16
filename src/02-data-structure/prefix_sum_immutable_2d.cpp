template<typename T>
class PrefixSum2D {
public:
    int n, m;
    vector<vector<T>> dp;

    PrefixSum2D()  : n(-1), m(-1) {}
    PrefixSum2D(vector<vector<T>>& grid) {
        n = (int) grid.size();
        assert(0 <= n);
        if(n == 0) { m = 0; return; }
        m = (int) grid[0].size();
        dp.resize(n+1, vector<T>(m+1, static_cast<T>(0)));
        
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                dp[i][j] = dp[i][j-1] + grid[i-1][j-1];
        for(int j = 1; j <= m; ++j)
            for(int i = 1; i <= n; ++i)
                dp[i][j] += dp[i-1][j];
    }
    T query(int x1, int y1, int x2, int y2) {
        assert(0<=x1&&x1<n && 0<=y1&&y1<m);
        assert(0<=x2&&x2<n && 0<=y2&&y2<m);
        int SA = dp[x2+1][y2+1];
        int SB = dp[x1][y2+1];
        int SC = dp[x2+1][y1];
        int SD = dp[x1][y1];
        return SA-SB-SC+SD;
    }
};

// Prefix Sum Immutable 2D - Shorter code
const int N = 102;
const int M = 102;
const int inf = 1e9;

int n;
int a[N][M];
int sum[N][M];

int query(int x1, int z1, int x2, int z2){
    return sum[x2][z2] + sum[x1-1][z1-1] - sum[x1-1][z2] - sum[x2][z1-1];
}

// initialization / at main()

for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
        cin >> a[i-1][j-1]; // 0-Indexed
        sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i-1][j-1];
    }
}

// query(x1, z1, x2, z2)