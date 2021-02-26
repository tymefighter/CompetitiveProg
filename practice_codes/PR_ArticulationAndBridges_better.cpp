#include<iostream>
#include<vector>

using namespace std;

void readInput(
    vector<vector<int> > &a
) {
    int n, m;
    cin >> n >> m;
    a.clear();
    a.resize(n);
    
    for(int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void dfsArtBridge(
    const vector<vector<int> > &a,
    vector<int> &dfs_num,
    vector<int> &dfs_low,
    vector<bool> &isArt,
    vector<pair<int, int> > &bridges,
    int u,
    int parent,
    int &currTime,
    int &numRootChildren
) {
    dfs_low[u] = dfs_num[u] = currTime ++;

    for(int v : a[u]) {
        if(v == parent)
            continue;
        else if(dfs_num[v] == -1) {
            dfsArtBridge(
                a,
                dfs_num,
                dfs_low,
                isArt,
                bridges,
                v,
                u,
                currTime,
                numRootChildren
            );

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);

            if(parent != -1) {
                if(dfs_low[v] >= dfs_num[u])
                    isArt[u] = true;
            }
            else
                numRootChildren ++;

            if(dfs_low[v] > dfs_num[u])
                bridges.push_back({u, v});
        }
        else
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

void findArtBridge(
    const vector<vector<int> > &a
) {
    int n = a.size(), currTime = 0;
    vector<int> dfs_num(n, -1), dfs_low(n, -1);
    vector<bool> isArt(n, false);
    vector<pair<int, int> > bridges;

    for(int u = 0;u < n;u++) {
        if(dfs_num[u] == -1) {
            int numRootChildren = 0;
            dfsArtBridge(
                a,
                dfs_num,
                dfs_low,
                isArt,
                bridges,
                u,
                -1,
                currTime,
                numRootChildren
            );

            if(numRootChildren > 1)
                isArt[u] = true;
        }

        if(isArt[u])
            cout << u << " ";
    }

    cout << "\n";
    for(const pair<int, int> &e : bridges)
        cout << "(" << e.first << ", " << e.second << ")\n";
}

int main() {

    vector<vector<int> > a;
    readInput(a);
    findArtBridge(a);

    return 0;
}