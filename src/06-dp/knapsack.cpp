vector<vector<int64>> dp;

int64 knapsack(vector<int64> &val, vector<int64> &wt, int item, int capacity) {
    // Casos base
    if(item <= 0 || capacity <= 0) return 0;

    if(dp[item][capacity] != -1) return dp[item][capacity];
    
    int itemCurr = item - 1;
    // Maximos items acumulado
    int64 lastMax = knapsack(val, wt, item-1, capacity);
    int64 currMax = 0;

    if(wt[itemCurr] <= capacity) {
        // Valor del item actual + el mejor item que cabe en la mochila
        currMax = val[itemCurr] + knapsack(val, wt, item - 1, capacity-wt[itemCurr]);
    }

    dp[item][capacity] = max(lastMax, currMax);
    return dp[item][capacity];
}
// vector<int> val{10, 40, 30, 50};
// vector<int> wt{5, 4, 6, 3};
// int n = val.size();
// int w = 10;
// knapsack(val, wt, n, w)