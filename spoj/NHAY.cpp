#include<iostream>
#include<queue>

using namespace std;

const long long m = static_cast<long long>(1e9 + 7);
const int p = 31;

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

long long p_inv = bin_exp(p, m - 2, m);
int nl;
long long h_val;


inline int char2int(char c) {return (c - 'a') + 1;} 

void read_needle() {
    h_val = 0;

    char c;
    long long pw = 1;
    for(int i = 0;i < nl;i++) {
        scanf("%c", &c);
        h_val = (h_val + char2int(c) * pw) % m;
        pw = (pw * p) % m;
    }

    scanf("%*c");
}

void solve() {
    char c;
    int i = 0;
    long long val = 0, pw = 1, inv_pw = 1;
    queue<long long> hp;

    while(scanf("%c", &c)) {
        if(c == '\n')
            break;

        val = (val + char2int(c) * pw) % m;
        pw = (pw * p) % m;

        if(hp.size() <= nl)
            hp.push(val);
        else {
            hp.pop();
            hp.push(val);
        }

        long long hash_sub;
        if(i == nl - 1)
            hash_sub = val;
        else if(i >= nl) {
            inv_pw = (inv_pw * p_inv) % m;
            hash_sub = (((val - hp.front()) % m) * inv_pw) % m;
            if(hash_sub < 0)
                hash_sub += m;
        }

        if(hash_sub == h_val)
            printf("%d\n", i - nl + 1);

        i ++;
    }
    printf("\n");
}

int main() {

    while(scanf("%d%*c", &nl) == 1) {
        read_needle();
        solve();
    }

    return 0;
}