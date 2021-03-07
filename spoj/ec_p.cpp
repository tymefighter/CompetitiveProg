#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void read_input(vector<vector<int> > &a) {
    int n, m;

    cin >> n >> m;
    a.resize(n);

    while(m --) {
        int u, v;

        cin >> u >> v;
        u --, v --;

        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void dfs_bridge(
    const vector<vector<int> > &a, 
    vector<int> &tin,
    vector<int> &low,
    int &count,
    int u,
    int parent,
    vector<pair<int, int> > &bridges
) {
    low[u] = tin[u] = count ++;

    for(int v : a[u]) {
        if(tin[v] == -1) {
            dfs_bridge(a, tin, low, count, v, u, bridges);
            low[u] = min(low[u], low[v]);
        }
        else if(v != parent)
            low[u] = min(low[u], tin[v]);

        if(low[v] > tin[u]) bridges.push_back({u, v});
    }
}

void order_bridges(vector<pair<int, int> > &bridges) {
    for(pair<int, int> &bridge : bridges) {
        if(bridge.first > bridge.second)
            bridge = {bridge.second, bridge.first};
    }

    sort(bridges.begin(), bridges.end());
}

void print_bridges(const vector<vector<int> > &a) {
    int n = a.size();
    vector<int> tin(n, -1), low(n, -1);
    vector<pair<int, int> > bridges;

    int count = 0;
    for(int u = 0;u < n;u++) {
        if(tin[u] == -1) dfs_bridge(a, tin, low, count, u, -1, bridges);
    }

    order_bridges(bridges);

    if(bridges.size() == 0) {
        cout << "Sin bloqueos\n";
        return;
    }

    cout << bridges.size() << "\n";
    for(pair<int, int> bridge : bridges)
        cout << bridge.first + 1 << " " << bridge.second + 1 << "\n";
}

int main() {

    enable_fast_io();

    int num_test_cases;
    cin >> num_test_cases;

    for(int case_num = 1;case_num <= num_test_cases;case_num++) {
        vector<vector<int> > a;
        read_input(a);
        cout << "Caso #" << case_num << "\n";
        print_bridges(a);
    }


    return 0;
}