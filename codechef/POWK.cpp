#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

enum State {UNVISITED, VISITED, EXPLORED};

int n, m;
vector<vector<int> > a;
vector<int> topo;
vector<State> state;

void reset() {
    a.clear();
    a.resize(n);
    state.clear();
    state.assign(n, UNVISITED);
    topo.clear();
}

void readInput() {
    scanf("%d %d ", &n, &m);

    reset();
    for(int i = 0;i < m;i++) {
        int v, u;
        scanf("k%d k%d ", &v, &u);
        u --, v --;
        a[u].push_back(v);
    }
}

bool dfs(int u) {
    state[u] = VISITED;

    for(int v : a[u]) {
        if(state[v] == UNVISITED) {
            if(!dfs(v))
                return false;
        }
        else if(state[v] == VISITED)
            return false;
    }

    state[u] = EXPLORED;
    topo.push_back(u);
    return true;
}

void solve() {
    for(int u = 0;u < n;u++) {
        if(state[u] == UNVISITED) {
            if(!dfs(u)) {
                printf("NO\n");
                return;
            }
        }
    }

    reverse(topo.begin(), topo.end());
    printf("YES\n");
    for(int x : topo)
        printf("k%d\n", x + 1);
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