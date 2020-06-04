#include<iostream>
#include<vector>

using namespace std;

const int N = static_cast<int>(2e5 + 5);
const int INF = static_cast<int>(1e9 + 5);

int n, a[N], b[N], c[N];
vector<vector<int> > t;

void operator+=(pair<int, int> &x, const pair<int, int> &y) {x = {x.first + y.first, x.second + y.second};}

void readInput() {
    scanf("%d ", &n);
    for(int i = 0;i < n;i++)
        scanf("%d %d %d ", &a[i], &b[i], &c[i]);

    t.clear();
    t.resize(n);
    for(int i = 0;i < n - 1;i++) {
        int u, v;
        scanf("%d %d ", &u, &v);
        u --, v --;
        t[u].push_back(v);
        t[v].push_back(u);
    }
}

void replaceWithMinAnc(int u, int parent, int minVal) {
    minVal = min(minVal, a[u]);
    a[u] = minVal;
    for(int v : t[u]) {
        if(v == parent)
            continue;

        replaceWithMinAnc(v, u, minVal);
    }
}

// returns this {number of unsolved type 1, number of unsolved type 2}
// type 1 -> have 0, want 1
// type 2 -> have 1, want 0
pair<int, int> dfs_shuffle(int u, int parent, long long &cost) {
    pair<int, int> val;

    if(b[u] != c[u]) {
        if(b[u] == 0)
            val = {1, 0};
        else
            val = {0, 1};
    }

    for(int v : t[u]) {
        if(v == parent)
            continue;

        val += dfs_shuffle(v, u, cost);
    }

    if(val.first <= val.second) {
        cost += 2 * val.first * static_cast<long long>(a[u]);
        val.second -= val.first;
        val.first = 0;
    }
    else {
        cost += 2 * val.second * static_cast<long long>(a[u]);
        val.first -= val.second;
        val.second = 0;
    }

    return val;
}

void solve() {
    
    replaceWithMinAnc(0, -1, INF);
    long long cost = 0;
    pair<int, int> val = dfs_shuffle(0, -1, cost);
    if(val.first == val.second && val.second == 0)
        printf("%lld\n", cost);
    else
        printf("-1\n");
}

int main() {

    readInput();
    solve();

    return 0;
}