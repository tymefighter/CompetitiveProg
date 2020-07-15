#include<iostream>
#include<map>

using namespace std;

const int N = 200005;
int n, p[N], q[N];


void readInput() {
    scanf("%d ", &n);
    int x;
    for(int i = 0;i < n;i++) {
        cin >> x;
        p[x] = i;
    }

    for(int i = 0;i < n;i++) {
        cin >> x;
        q[x] = i;
    }
}

void solve() {
    map<int, int> m;

    for(int i = 1;i <= n;i++) {
        int val = p[i] - q[i];
        val %= n;
        if(val < 0)
            val += n;
        if(m.find(val) == m.end())
            m[val] = 0;

        m[val] ++;
    }

    int ans = 0;
    for(auto p : m) {
        ans = max(p.second, ans);
    }
    printf("%d\n", ans);
}

int main() {
    readInput();
    solve();
    return 0;
}