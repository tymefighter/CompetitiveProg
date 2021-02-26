#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

const long long MOD = 998244353;
const long long ROOT = 565042129, ROOT_INV = 950391366;
const long long ROOT_PW = 1ll << 20ll;
const int B = 30;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void readInput(vector<long long> &a) {
    int n;
    cin >> n;
    a.resize(n);

    for(int i = 0;i < n;i++) cin >> a[i];
}

long long binary_exp(long long a, long long n) {
    if(n == 0) return 1;
    else if(n % 2 == 1) return (a * binary_exp(a, n - 1)) % MOD;
    else {
        long long val = binary_exp(a, n / 2);
        return (val * val) % MOD;
    }
}

inline long long inverse_fermat(long long a) {
    return binary_exp(a, MOD - 2);
}

inline void pad_zeros_behind(vector<long long> &a, int length) {
    while(a.size() < length) a.push_back(0);
}

void dft_helper(vector<long long> &a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        long long wlen = invert ? ROOT_INV : ROOT;

        for (int i = len; i < ROOT_PW; i <<= 1)
            wlen = (wlen * wlen) % MOD;

        for (int i = 0; i < n; i += len) {
            long long w = 1;
            for (int j = 0; j < len / 2; j++) {
                long long u = a[i + j], v = (a[i + j + len / 2] * w) % MOD;
                a[i + j] = u + v < MOD ? u + v : u + v - MOD;
                a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + MOD;
                w = (w * wlen) % MOD;
            }
        }
    }

    if (invert) {
        long long n_1 = inverse_fermat(n);
        for (long long &x : a)
            x = (x * n_1) % MOD;
    }
}

inline void dft(vector<long long> &a) {dft_helper(a, false);}
inline void idft(vector<long long> &a) {dft_helper(a, true);}

vector<long long> get_curr_value(const vector<long long> &a, long long b) {
    int n = a.size();
    int np = 0, nq = 0;

    for(long long x : a) {
        if(x & (1ll << b)) np ++;
        else nq ++;
    }

    vector<long long> p(n + 1), q(n + 1);
    p[0] = q[0] = 1;

    for(int i = 1;i <= n;i++) {
        if(i > np) p[i] = 0;
        else p[i] = ((((np - i + 1) * p[i - 1]) % MOD) * inverse_fermat(i)) % MOD;

        if(i > nq) q[i] = 0;
        else q[i] = ((((nq - i + 1) * q[i - 1]) % MOD) * inverse_fermat(i)) % MOD;
    }

    for(int i = 0;i <= n;i += 2) p[i] = 0;

    long long length = (1ll << static_cast<long long>(ceil(log2(n + 1))));
    pad_zeros_behind(p, length);
    pad_zeros_behind(q, length);

    dft(p);
    dft(q);

    for(int i = 0;i < p.size();i++) p[i] = (p[i] * q[i]) % MOD;
    idft(p);

    vector<long long> result(n + 1);
    for(int i = 0;i <= n;i++) result[i] = p[i];

    return result;
}

vector<long long> compute_answer(const vector<long long> &a) {
    int n = a.size();
    vector<vector<long long> > numSubseq(B);

    for(int b = 0;b < B;b++) numSubseq[b] = get_curr_value(a, b);
    
    vector<long long> ans(n + 1);

    ans[0] = 0;
    for(int m = 1;m <= n;m++) {
        long long value_subseq = 0;

        for(long long b = 0;b < B;b++)
            value_subseq = 
                (value_subseq + ((1ll << b) * numSubseq[b][m]) % MOD) % MOD;

        ans[m] = (ans[m - 1] + value_subseq) % MOD;
        if(ans[m] < 0) ans[m] += MOD;
    }

    return ans;
}

void solveQueries(const vector<long long> &ans) {
    int q;
    cin >> q;

    while(q --) {
        int m;
        cin >> m;

        cout << ans[m] << "\n";
    }
}

int main() {

    enable_fast_io();

    vector<long long> a;
    readInput(a);

    vector<long long> ans = compute_answer(a);
    solveQueries(ans);

    return 0;
}
