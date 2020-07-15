#include<iostream>
#include<vector>

using namespace std;

const long long mod = 1e9 + 7;
const int p = 31;
const int N = 1e6;

long long bin_exp(long long x, long long n) {
    if(n == 0)
        return 1;
    else if(n % 2)
        return (bin_exp(x, n - 1) * x) % mod;
    else {
        long long val = bin_exp(x, n / 2);
        return (val * val) % mod;
    }
}

const long long p_inv = bin_exp(p, mod - 2);
long long hp[N], inv_pw[N];
int n, m;
string s, t;

inline int char2int(char c) {return c - 'a' + 1;}

void build_hash_prefix_s() {
    long long pw = p;
    hp[0] = char2int(s[0]);
    inv_pw[0] = 1;

    for(int i = 1;i < n;i++) {
        hp[i] = (hp[i - 1] + char2int(s[i]) * pw) % mod;
        pw = (pw * p) % mod;
        inv_pw[i] = (inv_pw[i - 1] * p_inv) % mod;
    }
}

long long hash_subst(int i, int j) {
    long long val = ((hp[j] - (i > 0 ? hp[i - 1] : 0)) * inv_pw[i]) % mod;
    if(val < 0)
        val += mod;
    return val;
}

long long compute_hash_value_t() {
    long long val = 0, pw = 1;

    for(int i = 0;i < m;i++) {
        val = (val + char2int(t[i]) * pw) % mod;
        pw = (pw * p) % mod;
    }

    return val;
}

void solve() {
    build_hash_prefix_s();
    long long hash_value = compute_hash_value_t();
    vector<int> ans;

    for(int i = 0;i + m <= n;i++) {
        if(hash_subst(i, i + m - 1) == hash_value)
            ans.push_back(i);
    }

    if(ans.size() > 0) {
        cout << ans.size() << "\n";
        for(int idx : ans)
            cout << idx + 1 << " ";
    }
    else
        cout << "Not Found";

    cout << "\n\n";
}

int main() {

    int tc;
    cin >> tc;
    while(tc --) {
        cin >> s >> t;
        n = s.size();
        m = t.size();
        solve();
    }
    return 0;
}