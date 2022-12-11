function<double(long long)> get = [&](long long value) -> double {
    
};

long long low = 0, high = inf;
while (low + 3 < high) {
    long long q1 = (2LL * low + high) / 3LL;
    long long q2 = (low + 2LL * high) / 3LL;
    double v1 = get(q1);
    double v2 = get(q2);
    if (v1 > v2) {
        low = q1;
    } else {
        high = q2;
    }
}
double best = inf;
for (long long k = low; k <= high; k++) {
    best = min(best, get(k));
}