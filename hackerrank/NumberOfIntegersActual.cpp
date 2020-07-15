#include<iostream>
#include<algorithm>

using namespace std;

const int N = 105, K_VAL = 105, DIG = 10;
const long long MOD = 1000000007;

string l, r;
int K, n;
long long dpg[N][K_VAL][DIG], dpl[N][K_VAL][DIG];

void zero_pad_l() {
    while(l.size() < r.size())
        l.push_back('0');
}

void readInput() {
    cin >> l >> r >> K;
    n = r.size();

    reverse(r.begin(), r.end());
    reverse(l.begin(), l.end());

    while(r[r.size() - 1] == '0')
        r.pop_back();

    while(l[l.size() - 1] == '0')
        l.pop_back();

    zero_pad_l();
}

inline int char2int(char c) {return static_cast<int>(c - '0');}

void computeDP() {
    for(int k = 0;k <= K;k++) {
        for(int d = 0;d < DIG;d++) {
            if(k > 1)
                dpg[0][k][d] = 0;
            else if(k == 1)
                dpg[0][k][d] = (d >= char2int(l[0]) && d > 0 ? 1 : 0);
            else
                dpg[0][k][d] = (d >= char2int(l[0]) && d == 0 ? 1 : 0);

            if(k > 1)
                dpl[0][k][d] = 0;
            else if(k == 1)
                dpl[0][k][d] = (d < char2int(l[0]) && d > 0 ? 1 : 0);
            else
                dpl[0][k][d] = (d < char2int(l[0]) && d == 0 ? 1 : 0);
        }
    }

    for(int i = 1;i < n;i++) {
        for(int k = 0;k <= K;k++) {
            for(int d = 0;d < DIG;d++) {
                dpg[i][k][d] = dpl[i][k][d] = 0;

                if(d > char2int(l[i])) {
                    for(int dprev = 0;dprev < DIG;dprev ++) {
                        if(k > 0)
                            dpg[i][k][d] = (dpg[i][k][d] + dpl[i - 1][k - 1][dprev] + dpg[i - 1][k - 1][dprev]) % MOD;
                    }
                }
                else if(d == char2int(l[i])) {
                    for(int dprev = 0;dprev < DIG;dprev ++) {
                        int k0 = (d != 0 ? k - 1 : k);
                        if(k0 >= 0)
                            dpg[i][k][d] = (dpg[i][k][d] + dpg[i - 1][k0][dprev]) % MOD;
                    }
                }
                else {
                    dpg[i][k][d] = 0;
                }

                if(d > char2int(l[i])) {
                    dpl[i][k][d] = 0;
                }
                else if(d == char2int(l[i])) {
                    for(int dprev = 0;dprev < DIG;dprev++) {
                        int k0 = (d != 0 ? k - 1 : k);
                        if(k0 >= 0)
                            dpl[i][k][d] = (dpl[i][k][d] + dpl[i - 1][k0][dprev]) % MOD;
                    }
                }
                else {
                    for(int dprev = 0;dprev < DIG;dprev++) {
                        int k0 = (d != 0 ? k - 1 : k);
                        if(k0 >= 0)
                            dpl[i][k][d] = (dpl[i][k][d] + dpl[i - 1][k0][dprev] + dpg[i - 1][k0][dprev]) % MOD;
                    }
                }
            }
        }
    }
}

int numNonZero(const string &s) {
    int ct = 0;
    for(char c : s)
        ct += (c != '0' ? 1 : 0);
    return ct;
}

void solve() {
    long long ans = 0;
    
    for(int d = 1;d < char2int(r[n - 1]);d++)
        ans = (ans + dpg[n - 1][K][d]) % MOD;

    for(int i = n - 1;i > 0;i--) {
        if(l[i] != '0')
            break;

        for(int d = 1;d < DIG;d++) {
            ans = (ans + dpg[i - 1][K][d]) % MOD;
        }
    }

    bool isFrontEqual = r[n - 1] == l[n - 1];
    int kFront = K - (char2int(r[n - 1]) > 0 ? 1 : 0);

    for(int i = n - 2;i >= 0;i--) {
        if(kFront < 0)
            break;

        if(isFrontEqual) {
            for(int d = 0;d < char2int(r[i]);d++)
                ans = (ans + dpg[i][kFront][d]) % MOD;
        }
        else {
            for(int d = 0;d < char2int(r[i]);d++)
                ans = (ans + dpg[i][kFront][d] + dpl[i][kFront][d]) % MOD;
        }

        isFrontEqual = isFrontEqual && (l[i] == r[i]);
        kFront = kFront - (char2int(r[i]) > 0 ? 1 : 0);
    }

    ans = (ans + (kFront == 0 ? 1 : 0)) % MOD;

    if(numNonZero(l) == K)
        ans = (ans - 1) % MOD;

    if(ans < 0)
        ans = ans + MOD;

    cout << ans << "\n";
}

int main() {
    
    readInput();
    computeDP();
    solve();

    return 0;
}