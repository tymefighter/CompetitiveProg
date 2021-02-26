#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void readInput (
    vector<vector<int> > &a,
    vector<vector<int> > &aTrans
) {
    int n, m;
    cin >> n >> m;
    a.clear();
    a.resize(n);
    aTrans.clear();
    aTrans.resize(n);

    for(int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        aTrans[v].push_back(u);
    }
}

void dfsVertOrder (
    const vector<vector<int> > &a,
    vector<bool> &visited,
    vector<int> &vertOrder,
    int u
) {
    visited[u] = true;
    
    for(int v : a[u]) {
        if(!visited[v])
            dfsVertOrder(a, visited, vertOrder, v);
    }

    vertOrder.push_back(u);
}

void dfsFindComp (
    const vector<vector<int> > &aTrans,
    vector<bool> &visited,
    int u
) {
    cout << u << " ";
    visited[u] = true;

    for(int v : aTrans[u]) {
        if(visited[v] == false)
            dfsFindComp(aTrans, visited, v);
    }
}

void findSCC (
    const vector<vector<int> > &a,
    const vector<vector<int> > &aTrans
) {
    int n = a.size(), compNum = 0;
    vector<bool> visited(n, false);
    vector<int> vertOrder, comp(n, -1);

    for(int u = 0;u < n;u++) {
        if(!visited[u])
            dfsVertOrder(a, visited, vertOrder, u);
    }

    reverse(vertOrder.begin(), vertOrder.end());

    visited.assign(n, false);
    for(int u : vertOrder) {
        if(!visited[u]) {
            dfsFindComp(aTrans, visited, u);
            cout << "\n";
        }
    }
}

int main() {

    vector<vector<int> > a, aTrans;
    readInput(a, aTrans);
    findSCC(a, aTrans);

    return 0;
}