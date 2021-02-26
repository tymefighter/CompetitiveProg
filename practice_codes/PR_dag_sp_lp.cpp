#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int INF = static_cast<int>(1e8);

void readInput(vector<vector<pair<int, int> > > &a, int &source) {
    int n, m;
    cin >> n >> m;
    a.clear();
    a.resize(n);

    for(int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
    }

    cin >> source;
}

void dfsTsort(
    const vector<vector<pair<int, int> > > &a,
    vector<bool> &visited,
    vector<int> &topo,
    int u
) {
    visited[u] = true;

    for(pair<int, int> v : a[u]) {
        if(!visited[v.first])
            dfsTsort(a, visited, topo, v.first);
    }

    topo.push_back(u);
}

void tSort(
    const vector<vector<pair<int, int> > > &a,
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

void spLpDAG( // sp: shortest path, lp: longest path
    const vector<vector<pair<int, int> > > &a,
    int source,
    vector<int> &distMin,
    vector<int> &distMax,
    vector<int> &predMin,
    vector<int> &predMax
) {
    int n = a.size();
    vector<int> topo;
    tSort(a, topo);

    distMin.clear();
    distMin.assign(n, INF);
    distMax.clear();
    distMax.assign(n, -INF);
    predMin.clear();
    predMin.assign(n, -1);
    predMax.clear();
    predMax.assign(n, -1);

    distMin[source] = distMax[source] = 0;
    for(int u : topo) {
            
        for(pair<int, int> edge : a[u]) {
            int v = edge.first, w = edge.second;

            if(distMin[u] != INF && distMin[u] + w < distMin[v]) {
                distMin[v] = distMin[u] + w;
                predMin[v] = u;
            }

            if(distMax[u] != -INF && distMax[u] + w > distMax[v]) {
                distMax[v] = distMax[u] + w;
                predMax[v] = u;
            }
        }
    }
}

void printPath(int u, const vector<int> &pred) {
    if(u == -1)
        return;

    printPath(pred[u], pred);
    cout << u << " ";
}

void printOutput(
    const vector<int> &distMin,
    const vector<int> &distMax,
    const vector<int> &predMin,
    const vector<int> &predMax
) {
    int n = distMin.size();
    for(int u = 0;u < n;u++) {
        cout << "vertex: " << u << "\n";

        cout << "shortest dist: " << distMin[u] << ", shortest path: ";
        if(distMin[u] == INF)
            cout << "no path\n";
        else {
            printPath(u, predMin);
            cout << "\n";
        }

        cout << "longest dist: " << distMax[u] << ", longest path: ";
        if(distMin[u] == INF)
            cout << "no path\n";
        else {
            printPath(u, predMax);
            cout << "\n";
        }
    }
}

int main() {
    
    int source;
    vector<vector<pair<int, int> > > a;
    vector<int> distMin, distMax, predMin, predMax;

    readInput(a, source);
    spLpDAG(a, source, distMin, distMax, predMin, predMax);
    printOutput(distMin, distMax, predMin, predMax);

    return 0;
}