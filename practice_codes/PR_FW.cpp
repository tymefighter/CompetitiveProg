#include<iostream>
#include<vector>

using namespace std;

const int INF = static_cast<int>(1e8);

void readInput(
    vector<vector<int> > &dist,
    vector<vector<int> > &pred
) {
    int n, m;
    cin >> n >> m;
    dist.clear();
    dist.assign(n, vector<int>(n, INF));
    pred.clear();
    pred.assign(n, vector<int>(n, -1));

    for(int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
        pred[u][v] = u;
    }

    for(int i = 0;i < n;i++)
        dist[i][i] = 0;
}

void fwAPSP(
    vector<vector<int> > &dist,
    vector<vector<int> > &pred
) {
    int n = dist.size();
    for(int k = 0;k < n;k++) {
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if(
                    dist[i][k] != INF
                    && dist[k][j] != INF
                    && dist[i][k] + dist[k][j] < dist[i][j]
                ) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = pred[k][j];
                }
            }
        }
    }
}

void printPath(int u, int v, const vector<vector<int> > &pred) {
    if(u == v) {
        cout << u << " ";
        return;
    }

    printPath(u, pred[u][v], pred);
    cout << v << " ";
}

void printOutput(
    const vector<vector<int> > &dist,
    const vector<vector<int> > &pred
) {
    int n = dist.size();
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cout << i << " " << j << ", dist: " << dist[i][j] << ", path: ";
            if(dist[i][j] == INF)
                cout << "no path\n";
            else {
                printPath(i, j, pred);
                cout << "\n";
            }
        }
    }
}

int main() {

    vector<vector<int> > dist, pred;

    readInput(dist, pred);
    fwAPSP(dist, pred);
    printOutput(dist, pred);
    
    return 0;
}