#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int INF = static_cast<int>(1e8);

void readInput(vector<vector<int> > &a, int &source) {
    int n, m;
    cin >> n >> m;
    a.clear();
    a.resize(n);

    for(int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }

    cin >> source;
}

void dfsTsort(
    const vector<vector<int> > &a,
    vector<bool> &visited,
    vector<int> &topo,
    int u
) {
    visited[u] = true;

    for(int v : a[u]) {
        if(!visited[v])
            dfsTsort(a, visited, topo, v);
    }

    topo.push_back(u);
}

void tSort(
    const vector<vector<int> > &a,
    vector<int> &topo
) {
    int n = a.size();
    vector<bool> visited(n, false);
    topo.clear();

    for(int u = 0;u < n;u++) {
        if(!visited[u])
            dfsTsort(a, visited, topo, u);
    }

    reverse(topo.begin(), topo.end());
}

void getNumPaths(
    const vector<vector<int> > &a,
    int source,
    vector<int> &numPaths
) {
    int n = a.size();
    vector<int> topo;
    tSort(a, topo);

    numPaths.clear();
    numPaths.assign(n, 0);

    numPaths[source] = 1;
    for(int u : topo) {
        for(int v : a[u])
            numPaths[v] += numPaths[u];
    }
}

void printPath(int u, const vector<int> &pred) {
    if(u == -1)
        return;

    printPath(pred[u], pred);
    cout << u << " ";
}

void printOutput(
    const vector<int> &numPaths
) {
    int n = numPaths.size();
    for(int u = 0;u < n;u++) {
        cout
            << "number of paths to "
            << u
            << " are "
            << numPaths[u]
            << "\n";
    }
}

int main() {
    
    int source;
    vector<vector<int> > a;
    vector<int> numPaths;

    readInput(a, source);
    getNumPaths(a, source, numPaths);
    printOutput(numPaths);

    return 0;
}