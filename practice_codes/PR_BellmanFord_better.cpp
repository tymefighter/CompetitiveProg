#include<iostream>
#include<vector>

using namespace std;

struct Edge {
    int u, v, w;
};

const int INF = static_cast<int>(1e8);

void readInput(int &n, vector<Edge> &elist, int &source) {
    int m;
    cin >> n >> m;
    elist.clear();
    elist.resize(m);
    for(int i = 0;i < m;i++)
        cin >> elist[i].u >> elist[i].v >> elist[i].w;

    cin >> source;
}

bool bellmanFord(
    int n,
    const vector<Edge> &elist,
    vector<int> &dist,
    vector<int> &pred,
    int source
) {
    dist.clear();
    dist.assign(n, INF);
    pred.clear();
    pred.assign(n, -1);

    dist[source] = 0;
    for(int i = 0;i < n - 1;i++) {
        for(const Edge &edge : elist) {
            int u = edge.u, v = edge.v, w = edge.w;
            if(dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pred[v] = u;
            }
        }
    }

    for(const Edge &edge : elist) {
        int u = edge.u, v = edge.v, w = edge.w;
        if(dist[u] != INF && dist[v] > dist[u] + w)
            return false;
    }

    return true;
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
        if(dist[u] == INF)
            cout << "No Path\n";
        else {
            printPath(u, pred);
            cout << "\n";
        }
    }
}

int main() {

    int n, source;
    vector<Edge> elist;
    vector<int> dist, pred;

    readInput(n, elist, source);
    if(bellmanFord(n, elist, dist, pred, source))
        printInfo(dist, pred);
    else
        cout << "Negative Cycle Found\n";

    return 0;
}