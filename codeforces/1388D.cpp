#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 200005;
int n, b[N];
bool visited[N];
long long c[N];

vector<vector<int> > a;

void readInput() {
    scanf("%d ", &n);
    for(int i = 0;i < n;i++)
        scanf("%lld ", &c[i]);

    a.clear();
    a.resize(n);
    for(int i = 0;i < n;i++) {
        scanf("%d ", &b[i]);
        if(b[i] != -1) {
            b[i] --;
            a[i].push_back(b[i]);
        }
        visited[i] = false;
    }
}

vector<int> topo;

void dfs(int u) {
    visited[u] = true;
    for(int v : a[u]) {
        if(!visited[v])
            dfs(v);
    }
    topo.push_back(u);
}

void tsort() {
    topo.clear();
    for(int u = 0;u < n;u++) {
        if(!visited[u])
            dfs(u);
    }

    reverse(topo.begin(), topo.end());
}

void solve() {
    long long ans = 0;
    vector<int> idx, leftOut;

    tsort();

    for(int u : topo) {
        if(c[u] >= 0) {
            if(b[u] != -1)
                c[b[u]] += c[u];

            ans += c[u];
            idx.push_back(u);
        }
        else
            leftOut.push_back(u);
    }

    reverse(leftOut.begin(), leftOut.end());
    for(int u : leftOut) {
        ans += c[u];
        idx.push_back(u);
    }

    printf("%lld\n", ans);
    for(int u : idx)
        cout << u  + 1<< " ";
    cout << "\n";
}

int main() {

    readInput();
    solve();

    return 0;
}