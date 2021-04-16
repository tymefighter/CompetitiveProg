#include <iostream>
#include <map>

using namespace std;

const int N = 500000;
int n, m;
long long l, k;
int a[N], b[N];

map<int, int> mp;

long long gcd(long long x, long long y) {
    return x == 0 ? y : gcd(y % x, x);
}

long long lcm(long long x, long long y) {
    return x * (y / gcd(x, y));
}

void read_input() {
    scanf("%d %d %lld ", &n, &m, &k);

    for(int i = 0;i < n;i++) scanf("%d ", &a[i]);
    for(int i = 0;i < m;i++) {
        scanf("%d ", &b[i]);
        mp[b[i]] = i;
    }

    l = lcm(n, m);
}

long long extended_euclid(
    long long p, long long q,
    long long &x, long long &y
) {
    if(p == 0) {
        x = 0;
        y = 1;
        return q;
    }
    
    long long x1, y1;
    long long g = extended_euclid(q % p, p, x1, y1);
    x = y1 - (q / p) * x1;
    y = x1;

    return g;
}

long long coeff[N];

void compute_coeff() {
    long long x, y, g;
    g = extended_euclid(n, m, x, y);

    for(int i = 0;i < n;i++) {
        if(mp.find(a[i]) == mp.end()) {
            coeff[i] = -1;
            continue;
        }

        long long a1 = i, a2 = mp[a[i]];

        if((a1 - a2) % g) {
            coeff[i] = -1;
            continue;
        }

        coeff[i] = ((a1 * (m / g) * y) % l + (a2 * (n / g) * x) % l) % l;
        if(coeff[i] < 0) coeff[i] += l;
    }
}

long long get_num_wrong(long long time) {
    long long sum_correct = 0;

    for(int i = 0;i < n;i++) {
        if(coeff[i] == -1) continue;

        long long val = (time - 1 - coeff[i]);
        if(val < 0) continue;
        val = val / l + 1;

        sum_correct += val;
    }

    return time - sum_correct;
}

long long binary_search() {
    long long low = 0, high = static_cast<long long>(1e18);
    long long ans_time = high;

    while(low <= high) {
        long long mid = (low + high) >> 1;
        long long num_wrong = get_num_wrong(mid);

        if(num_wrong < k) low = mid + 1;
        else {
            ans_time = min(ans_time, mid);
            high = mid - 1;
        }
    }

    return ans_time;
}

void solve() {
    compute_coeff();
    printf("%lld\n", binary_search());
}

int main() {

    read_input();
    solve();

    return 0;
}