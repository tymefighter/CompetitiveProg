#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Edge {
    int u, v, w;

    Edge(int u_, int v_, int w_):
        u(u_),
        v(v_),
        w(w_) {}

    ~Edge() {}
};

struct CompEdge {
    bool operator() (const Edge &e1, const Edge &e2) {
        return e1.w > e2.w;
    }
};

void readInput(vector<vector<pair<int, int> > > &a) {
    int n, m;
    cin >> n >> m;
    a.clear();
    a.resize(n);
    for(int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
}

void primMST(const vector<vector<pair<int, int> > > &a) {
    int n = a.size(), totalWt = 0;
    priority_queue<Edge, vector<Edge>, CompEdge> pq;
    vector<bool> taken(n, false);

    taken[0] = true;
    for(pair<int, int> v : a[0])
        pq.push(Edge(0, v.first, v.second));

    while(!pq.empty()) {
        Edge e = pq.top();
        pq.pop();

        if(taken[e.v])
            continue;

        taken[e.v] = true;
        totalWt += e.w;
        cout << "(" << e.u << ", " << e.v << ") : " << e.w << "\n";

        for(pair<int, int> v : a[e.v]) {
            if(!taken[v.first])
                pq.push(Edge(e.v, v.first, v.second));
        }
    }

    cout << "Total Weight: " << totalWt << "\n";
}

int main() {

    vector<vector<pair<int, int> > > a;
    readInput(a);
    primMST(a);

    return 0;
}