#include<iostream>
#include<vector>

using namespace std;

const int N = static_cast<int>(1e6);
const int p = 31;
const long long mod = static_cast<long long>(1e9 + 7);

long long bin_exp(long long a, long long n, const long long &mod_val) {
    if(n == 0)
        return 1;
    else if(n % 2)
        return (bin_exp(a, n - 1, mod_val) * a) % mod_val;
    else {
        long long val = bin_exp(a, n / 2, mod_val);
        return (val * val) % mod_val;
    }
}
long long p_inv = bin_exp(p, mod - 2, mod);

int n;
string s;
long long hp[N], inv_pw[N];

inline int char2int(char c) {return (c - 'a') + 1;}

void build_hash_prefix() {
    long long pw = 1;

    for(int i = 0;i < n;i++) {
        hp[i] = ((i > 0 ? hp[i - 1] : 0) + char2int(s[i]) * pw) % mod;
        inv_pw[i] = (i == 0 ? 1 : (inv_pw[i - 1] * p_inv) % mod);
        pw = (pw * p) % mod;
    }
}

long long hash_subst(int i, int j) {
    long long val = ((hp[j] - (i > 0 ? hp[i - 1] : 0)) * inv_pw[i]) % mod;
    if(val < 0)
        val += mod;
    return val;
}

bool is_length_present(int pre_len) {

    const long long &h_val = hp[pre_len - 1];

    for(int i = 1;i + pre_len < n;i++) {
        if(hash_subst(i, i + pre_len - 1) == h_val) {
            return true;
        }
    }

    return false;
}

bool solve() {

    vector<int> match_len;

    for(int l = 1;l < n;l++) {
        if(hash_subst(0, l - 1) == hash_subst(n - l, n - 1))
            match_len.push_back(l);
    }

    if(match_len.size() == 0)
        return false;

    int low = 0, high = match_len.size() - 1, mid, ans = -1;

    while(low <= high) {
        mid = (low + high) >> 1;
        if(is_length_present(match_len[mid])) {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    if(ans == -1)
        return false;

    cout << s.substr(0, match_len[ans]) << "\n";
    return true;
}

int main() {
    cin >> s;
    n = s.size();
    build_hash_prefix();

    if(!solve())
        cout << "Just a legend\n";
    return 0;
}