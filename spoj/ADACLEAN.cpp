#include<iostream>
#include<vector>
#include<set>

using namespace std;

const long long mod1 = static_cast<long long>(1e9 + 7);
const long long mod2 = static_cast<long long>(1e9 + 9);
const int p1 = 31, p2 = 37;
const int N = static_cast<int>(1e5);

long long bin_exp(long long x, long long n, const long long mod) {
    if(n == 0)
        return 1;
    else if(n % 2)
        return (bin_exp(x, n - 1, mod) * x) % mod;
    else {
        long long val = bin_exp(x, n / 2, mod);
        return (val * val) % mod;
    }
}

long long p1_inv = bin_exp(p1, mod1 - 2, mod1);
long long p2_inv = bin_exp(p2, mod2 - 2, mod2);

char a[N];
int n, k;
long long hp1[N], hp2[N], inv_pw1[N], inv_pw2[N];
set<pair<long long, long long> > s;

inline int char2int(char c) {return (c - 'a') + 1;}

void readInput() {
    scanf("%d%d ", &n, &k);
    for(int i = 0;i < n;i++)
        scanf("%c ", &a[i]);
}

void build_hash_prefix() {
    long long pw1 = 1, pw2 = 1;

    for(int i = 0;i < n;i++) {
        hp1[i] = ((i > 0 ? hp1[i - 1] : 0) + char2int(a[i]) * pw1) % mod1;
        hp2[i] = ((i > 0 ? hp2[i - 1] : 0) + char2int(a[i]) * pw2) % mod2;
        pw1 = (pw1 * p1) % mod1;
        pw2 = (pw2 * p2) % mod2;
        inv_pw1[i] = (i == 0 ? 1 : (inv_pw1[i - 1] * p1_inv) % mod1);
        inv_pw2[i] = (i == 0 ? 1 : (inv_pw2[i - 1] * p2_inv) % mod2);
    }
}

pair<long long, long long> hash_subst(int i, int j) {
    long long val1 = ((hp1[j] - (i > 0 ? hp1[i - 1] : 0)) * inv_pw1[i]) % mod1;
    if(val1 < 0)
        val1 += mod1;
    long long val2 = ((hp2[j] - (i > 0 ? hp2[i - 1] : 0)) * inv_pw2[i]) % mod2;
    if(val2 < 0)
        val2 += mod2;

    return {val1, val2};
}

void solve() {
    int ans = 0;
    s.clear();
    build_hash_prefix();

    for(int i = 0;i + k <= n;i++)
        s.insert(hash_subst(i, i + k - 1));

    printf("%lu\n", s.size());
}

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        readInput();
        solve();
    }
    return 0;
}