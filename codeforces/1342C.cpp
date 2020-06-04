#include<iostream>

using namespace std;

const int N = static_cast<int>(4e4 + 5);
int a, b, q;
int pre[N];

long long numSat(long long h) {
    return (h / (a * b)) * pre[a * b - 1] + pre[h % (a * b)];
}

void solve_queries() {
    for(int i = 0;i < a * b;i++) {
        pre[i] = (i > 0 ? pre[i - 1] : 0) + ((i % a) % b == (i % b) % a ? 1 : 0);
    }

    while(q --) {
        long long l, r;
        cin >> l >> r;
        cout << (r - l + 1) - (numSat(r) - (l > 0 ? numSat(l - 1) : 0)) << " ";
    }
    cout << "\n";
}

int main() {

    int t;
    cin >> t;
    while(t --) {
        cin >> a >> b >> q;
        if(a > b)
            swap(a, b);
        solve_queries();
    }

    return 0;
}