#include<iostream>
#include<vector>
#include<queue>

using namespace std;

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

void ssspDijkstra(
    const vector<vector<pair<int, int> > > &a, // (vert, weight)
    vector<int> &dist,
    vector<int> &pred,
    int source
) {
    priority_queue<
        pair<int, int>, 
        vector<pair<int, int> >, 
        greater<pair<int, int> >
        > pq; // (dist, vert)

    int n = a.size();
    dist.clear();
    dist.assign(n, -1);
    pred.clear();
    pred.assign(n, -1);

    dist[source] = 0;
    pq.push({0, source});

    while(!pq.empty()) {
        pair<int, int> v = pq.top();
        int u = v.second, ds = v.first;
        pq.pop();

        if(ds > dist[u]) // lazy deletion
            continue;

        for(pair<int, int> v : a[u]) {
            if(dist[v.first] == -1 || dist[v.first] > dist[u] + v.second) {
                pred[v.first] = u;
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first], v.first});
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

void printInfo(const vector<int> &dist, const vector<int> &pred) {
    for(int u = 0;u < dist.size();u++) {
        cout << "vert: " << u << ", dist: " << dist[u] << " | Path: ";
        if(dist[u] == -1)
            cout << "No Path\n";
        else {
            printPath(u, pred);
            cout << "\n";
        }
    }
}

int main() {

    int source;
    vector<vector<pair<int, int> > > a;
    vector<int> dist, pred;

    readInput(a, source);
    ssspDijkstra(a, dist, pred, source);
    printInfo(dist, pred);

    return 0;
}
