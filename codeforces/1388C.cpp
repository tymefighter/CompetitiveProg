#include<iostream>
#include<vector>

using namespace std;

const int N = 100005;

int n, m;
long long p[N], h[N], numSub[N], numBad[N];
vector<vector<int> > a;

void readInput() {
    scanf("%d %d ", &n, &m);
    for(int i = 0;i < n;i++)
        scanf("%lld ", &p[i]);
    
    for(int i = 0;i < n;i++)
        scanf("%lld ", &h[i]);

    a.clear();
    a.resize(n);

    for(int i = 0;i < n - 1;i++) {
        int u, v;
        scanf("%d %d ", &u, &v);
        u --, v --;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

bool dfs(int u, int parent) {
    numSub[u] = p[u];

    for(int v : a[u]) {
        if(v == parent)
            continue;

        if(!dfs(v, u))
            return false;

        numSub[u] += numSub[v];
    }

    numBad[u] = numSub[u] - h[u];

    if(numBad[u] < 0 || numBad[u] % 2 != 0)
        return false;

    numBad[u] /= 2;

    long long numGoodu = numSub[u] - numBad[u], goodSum = 0;
    for(int v : a[u]) {
        if(v == parent)
            continue;

        goodSum += numSub[v] - numBad[v];
    }

    return goodSum <= numGoodu;
}

void solve() {
    if(dfs(0, -1))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {

    int t;
    scanf("%d ", &t);

    while(t --) {
        readInput();
        solve();
    }

    return 0;
}