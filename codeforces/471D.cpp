#include<iostream>
#include<vector>

using namespace std;

const int N = static_cast<int>(2e5);
const long long INF = static_cast<long long>(1e15);
int n, w, m, pi[2 * N + 1];
long long da[N], db[N], s[2 * N + 1];

void readInput() {

    long long prev_x;
    cin >> prev_x;
    for(int i = 1;i < n;i++) {
        long long x;
        cin >> x;
        da[i - 1] = x - prev_x;
        prev_x = x;
    }

    cin >> prev_x;
    for(int i = 1;i < w;i++) {
        long long x;
        cin >> x;
        db[i - 1] = x - prev_x;
        prev_x = x;
    }

    n --, w --;
    m = n + w + 1;
    for(int i = 0;i < w;i++)
        s[i] = db[i];

    s[w] = INF;

    for(int i = w + 1;i < m;i++)
        s[i] = da[i - (w + 1)];
}

void compute_prefix() {
    pi[0] = 0;
    for(int i = 1;i < m;i++) {
        int j = pi[i - 1];

        while(j > 0 && s[j] != s[i])
            j = pi[j - 1];

        if(s[j] == s[i])
            pi[i] = j + 1;
        else
            pi[i] = 0;
    }
}

void solve() {
    compute_prefix();
    int ans = 0;

    for(int i = w + 1;i < m;i++)
        ans += (pi[i] >= w ? 1 : 0);

    cout << ans << "\n";
}

int main() {
    cin >> n >> w;

    if(w == 1)
        cout << n << "\n";
    else {
        readInput();
        solve();
    }

    return 0;
}