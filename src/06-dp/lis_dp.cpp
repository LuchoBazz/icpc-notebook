int lis(int arr[], int i, int n, int prev) {
    // Base case: nothing is remaining
    if (i == n) {
        return 0;
    }
    int excl = lis(arr, i + 1, n, prev); 
    int incl = 0;
    if (arr[i] > prev) {
        incl = 1 + lis(arr, i + 1, n, arr[i]);
    }
    return max(incl, excl);
}