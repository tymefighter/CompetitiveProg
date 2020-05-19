#include<iostream>

using namespace std;

const long long mod1 = 1e9 + 7, mod2 = 1e9 + 9;
const int p1 = 257, p2 = 263;
const int N = 1e5;

long long bin_exp(long long x, long long n, const long long &mod) {
    if(n == 0)
        return 1;
    else if(n % 2)
        return (bin_exp(x, n - 1, mod) * x) % mod;
    else {
        long long val = bin_exp(x, n / 2, mod);
        return (val * val) % mod;
    }
}

const long long p1_inv = bin_exp(p1, mod1 - 2, mod1);
const long long p2_inv = bin_exp(p2, mod2 - 2, mod2);

int n, m, minCount;
string s, t;
long long hps_1[N], hps_2[N], hpt_1[N], hpt_2[N];
long long inv_pw1[N], inv_pw2[N];

inline int char2int(char c) {return static_cast<unsigned>(c) + 1;}

void build_hash_prefixes() {
    long long pw1, pw2;

    pw1 = pw2 = 1;
    for(int i = 0;i < n;i++) {
        hps_1[i] = ((i > 0 ? hps_1[i - 1] : 0) + char2int(s[i]) * pw1) % mod1;
        hps_2[i] = ((i > 0 ? hps_2[i - 1] : 0) + char2int(s[i]) * pw2) % mod2;
        pw1 = (pw1 * p1) % mod1;
        pw2 = (pw2 * p2) % mod2;
    }

    pw1 = pw2 = 1;
    for(int i = 0;i < m;i++) {
        hpt_1[i] = ((i > 0 ? hpt_1[i - 1] : 0) + char2int(t[i]) * pw1) % mod1;
        hpt_2[i] = ((i > 0 ? hpt_2[i - 1] : 0) + char2int(t[i]) * pw2) % mod2;
        pw1 = (pw1 * p1) % mod1;
        pw2 = (pw2 * p2) % mod2;
    }

    inv_pw1[0] = inv_pw2[0] = 1;
    for(int i = 1;i < max(n, m);i++) {
        inv_pw1[i] = (inv_pw1[i - 1] * p1_inv) % mod1;
        inv_pw2[i] = (inv_pw2[i - 1] * p2_inv) % mod2;
    }
}

pair<long long, long long> hash_subst_s(int i, int j) {
    long long val1 = ((hps_1[j] - (i > 0 ? hps_1[i - 1] : 0)) * inv_pw1[i]) % mod1;
    if(val1 < 0)
        val1 += mod1;

    long long val2 = ((hps_2[j] - (i > 0 ? hps_2[i - 1] : 0)) * inv_pw2[i]) % mod2;
    if(val2 < 0)
        val2 += mod2;
    
    return {val1, val2};
}

bool RabinKarp(int len) {
    int countVal = 0;
    pair<long long, long long> hash_val = {hpt_1[len - 1], hpt_2[len - 1]};

    for(int i = 0;i + len <= n;i++)
        countVal += (hash_subst_s(i, i + len - 1) == hash_val ? 1 : 0);

    return countVal >= minCount;
}

void solve() {
    int low = 1, high = m, mid, ans = 0;

    while(low <= high) {
        mid = (low + high) >> 1;
        if(RabinKarp(mid)) {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    cout << (ans == 0 ? "IMPOSSIBLE" : t.substr(0, ans)) << "\n";
}

int main() {
    getline(cin, s);
    getline(cin, t);
    cin >> minCount;
    n = s.size(), m = t.size();

    build_hash_prefixes();
    solve();

    return 0;
}
