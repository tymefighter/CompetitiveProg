#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, k;
vector<vector<int> > a;
vector<bool> visited;

void readInput() {
    scanf("%d %d ", &n, &k);
    a.clear();
    a.resize(n);
    visited.clear();
    visited.assign(n, false);

    for(int i = 0;i < k;i++) {
        int u, v;
        scanf("%d %d ", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

int dfs(int u) {
    visited[u] = true;
    int sz = 1;
    for(int v : a[u]) {
        if(!visited[v])
            sz += dfs(v);
    }
    return sz;
}

void solve() {
    vector<int> ans;

    for(int u = 0;u < n;u++) {
        if(!visited[u])
            ans.push_back(dfs(u));
    }

    sort(ans.begin(), ans.end());
    printf("%d\n", static_cast<int>(ans.size()));
    for(int x : ans)
        printf("%d ", x);
    printf("\n");
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