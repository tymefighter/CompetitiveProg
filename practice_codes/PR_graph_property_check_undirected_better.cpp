#include<iostream>
#include<vector>

using namespace std;

enum EdgeType {TREE, BACK};

void readInput(
    vector<vector<pair<int, int> > > &a, // (vert, edge number)
    vector<pair<int, int> > &edges
) {
    int n, m;
    cin >> n >> m;
    a.clear();
    a.resize(n);
    edges.clear();
    edges.resize(m);

    for(int i = 0;i < m;i++) {
        cin >> edges[i].first >> edges[i].second;
        a[edges[i].first].push_back({edges[i].second, i});
        a[edges[i].second].push_back({edges[i].first, i});
    }
}

void dfsEdgeProp(
    const vector<vector<pair<int, int> > > &a,
    vector<bool> &visited,
    vector<EdgeType> &edgeProp,
    int u,
    int parent
) {
    visited[u] = true;

    for(pair<int, int> v : a[u]) {
        if(v.first == parent)
            continue;

        if(!visited[v.first]) {
            edgeProp[v.second] = TREE;
            dfsEdgeProp(a, visited, edgeProp, v.first, u);
        }
        else
            edgeProp[v.second] = BACK;
    }
}

void edgePropertyCheck(
    const vector<vector<pair<int, int> > > &a,
    vector<pair<int, int> > &edges,
    vector<EdgeType> &edgeProp
 ) {
    int n = a.size(), m = edges.size();
    vector<bool> visited(n, false);
    edgeProp.clear();
    edgeProp.resize(m);

    for(int u = 0;u < n;u++) {
        if(!visited[u])
            dfsEdgeProp(a, visited, edgeProp, u, -1);
    }
}

void printOutput(
    vector<pair<int, int> > &edges,
    vector<EdgeType> &edgeProp
) {
    int m = edges.size();
    for(int i = 0;i < m;i++) {
        cout << "(" << edges[i].first << ", " << edges[i].second << ") : ";
        if(edgeProp[i] == TREE)
            cout << "Tree\n";
        else
            cout << "Back\n";
    }
}

int main() {

    int t;
    cin >> t;
    while(t --) {
        vector<vector<pair<int, int> > > a;
        vector<pair<int, int> > edges;
        vector<EdgeType> edgeProp;

        readInput(a, edges);
        edgePropertyCheck(a, edges, edgeProp);
        printOutput(edges, edgeProp);
    }
    return 0;
}