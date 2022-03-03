// Longest Increasing Subsequence O(n*lg(n))
template <typename T>
int lis(const vector<T> &a) {
    vector<T> u;
    for (const T &x : a) {
        auto it = lower_bound(u.begin(), u.end(), x);
        if (it == u.end()) {
            u.push_back(x);
        } else {
            *it = x;
        }
    }
    return (int) u.size();
}
// LIS O(nlog(n)) Para longest non-decreasing cambiar lower_bound por upper_bound
int lis(){
	LIS.clear();
	for(int i = 0; i < N; i++){
		auto id = lower_bound(LIS.begin(), LIS.end(), A[i]);
		if(id == LIS.end()){
			LIS.push_back(A[i]);
			dp[i] = LIS.size();
		} 
		else{
			int idx = id - LIS.begin();
			LIS[idx] = A[i];
			dp[i] = idx + 1;
		}
	}
	return LIS.size();
}
// METODO PARA RECONSTRUIR LIS. Para non-decreasing cambiar < por <=
stack<int> rb;
void build(){
	int k = LIS.size();
	int cur = oo;
	for(int i = N - 1; i >= 0, k; i--){
		if(A[i] < cur && k == dp[i]){
			cur = A[i];
			rb.push(A[i]);
			k--;
		}
	}
}