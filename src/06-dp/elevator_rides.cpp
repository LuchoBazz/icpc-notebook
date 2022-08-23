// https://cses.fi/problemset/task/1653
int n; // the number of people
ll x;  // maximum allowed weight in the elevator
vector<ll> W; // w1, w2, ..., wn: the weight of each person.
 
struct Answer {
    int rides; // is the minimum number of rides for a subset mask
    ll lastW;  // is the minimum weight of the last ride
 
    bool operator<(const Answer &other) const {
        if(rides == other.rides) return lastW < other.lastW;
        return rides < other.rides;
    }
 
    bool operator>(const Answer &other) const {
        if(rides == other.rides) return lastW > other.lastW;
        return rides > other.rides;
    }
};

// at main()
vector<Answer> dp((1 << n) + 2);
dp[0] = {1, 0}; // We set the value for an empty group as follows:
for(int mask = 1; mask < (1 << n); ++mask) {
    dp[mask] = {inf, inf};
    for(int p = 0; p < n; ++p) {
        if(mask & (1 << p)) {
            Answer option = dp[mask ^ (1 << p)];
            if(option.lastW + W[p] <= x) {
                // add p to an existing ride
                option.lastW += W[p];
            } else {
                // reserve a new ride for p
                option.rides++;
                option.lastW = W[p];
            }
            dp[mask] = min(dp[mask], option);
        }
    }
}

cout << dp[(1 << n) - 1].rides << endl;