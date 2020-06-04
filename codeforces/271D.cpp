#include<iostream>
#include<cstring>
#include<set>

using namespace std;

const long long mod1 = 1e9 + 7, mod2 = 1e9 + 9;
const int p1 = 31, p2 = 37;
const int N = 1500;

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

int n, k;
char s[N + 1];
bool is_bad[27]; // char: 1 .. 26
long long hp1[N], inv_pw1[N];
long long hp2[N], inv_pw2[N];

void readInput() {
    char good[27];
    scanf("%s", s);
    n = strlen(s);
    scanf("%s", good);

    for(int i = 1;i <= 26;i++)
        is_bad[i] = good[i - 1] == '0';
    scanf("%d", &k);
}

inline int char2int(char c) {return c - 'a' + 1;}

void build_hash_prefix() {
    hp1[0] = hp2[0] = char2int(s[0]);
    inv_pw1[0] = inv_pw2[0] = 1;
    long long pw1 = p1, pw2 = p2;

    for(int i = 1;i < n;i++) {
        hp1[i] = (hp1[i - 1] + char2int(s[i]) * pw1) % mod1;
        pw1 = (pw1 * p1) % mod1;
        inv_pw1[i] = (inv_pw1[i - 1] * p1_inv) % mod1;

        hp2[i] = (hp2[i - 1] + char2int(s[i]) * pw2) % mod2;
        pw2 = (pw2 * p2) % mod2;
        inv_pw2[i] = (inv_pw2[i - 1] * p2_inv) % mod2;
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

    set<pair<long long, long long> > dist_sub;

    build_hash_prefix();

    for(int i = 0;i < n;i++) {
        int num_bad = 0;
        for(int j = i;j < n;j ++) {
            num_bad += (is_bad[char2int(s[j])] ? 1 : 0);
            if(num_bad > k)
                break;
            dist_sub.insert(hash_subst(i, j));
        }
    }

    cout << dist_sub.size() << "\n";
}

int main() {
    readInput();
    solve();
    return 0;
}