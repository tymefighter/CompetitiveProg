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

void printPath(
    int v,
    int u,
    vector<int> &pred
) {
    if(u == v) {
        cout << v << " ";
        return;
    }
    
    printPath(v, pred[u], pred);
    cout << u << " ";
}

bool dfsCycleDet( // returns true if cycle is found (also prints the cycle)
    const vector<vector<int> > &a,
    vector<bool> &visited,
    vector<int> &pred,
    int u,
    int parent
) {
    pred[u] = parent;
    visited[u] = true;
    
    for(int v : a[u]) {
        if(v == parent)
            continue;
        else if(!visited[v]) {
            if(dfsCycleDet(a, visited, pred, v, u))
                return true;
        }
        else {
            printPath(v, u, pred);
            cout << v << "\n";
            return true;
        }
    }

    return false;
}

void cycleDetection(
    const vector<vector<int> > &a
) {
    int n = a.size();
    vector<bool> visited(n, false);
    vector<int> pred(n, -1);

    for(int u = 0;u < n;u++) {
        if(!visited[u]) {
            if(dfsCycleDet(a, visited, pred, u, -1))
                return;
        }
    }

    cout << "No Cycle Present\n";
}

int main() {

    vector<vector<int> > a;

    readInput(a);
    cycleDetection(a);

    return 0;
}