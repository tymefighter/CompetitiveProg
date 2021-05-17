#include <iostream>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 500;
int n, p[N], a[N][N];

void read() {
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> p[i];
}

void fill(int i, int m) {
    int j = i, num_filled = 1;
    a[i][i] = m;

    while(num_filled < m) {
        if(i < n - 1 && a[i + 1][j] == -1) i ++;
        else j --;

        a[i][j] = m;
        num_filled ++;
    }
}

void solve() {
    for(int i = 0;i < n;i++)
        for(int j = 0;j <= i;j++) a[i][j] = -1;

    for(int i = n - 1;i >= 0;i--)
        fill(i, p[i]);

    for(int i = 0;i < n;i++) {
        for(int j = 0;j <= i;j++)
            cout << a[i][j] << " ";

        cout << "\n";
    }
}

int main() {

    enable_fast_io();

    read();
    solve();

    return 0;
}