#include<iostream>
#include<vector>

using namespace std;

enum State {UNVIS, VIS, EXP};
enum EdgeType {TREE, BACK, CROSS, FORW};

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
    }
}

void printEdge(int u, int v, EdgeType edgeType) {
    cout << "(" << u << ", " << v << ") : ";

    if(edgeType == TREE) cout << "Tree";
    else if(edgeType == BACK) cout << "Back";
    else if(edgeType == CROSS) cout << "Cross";
    else cout << "Forward";

    cout << "\n";
}

void dfsEdgePropertyCheck(
    const vector<vector<int> > &a,  // graph
    vector<int> &tin,               // entry time
    vector<State> &state,           // state of each vert
    int u,                          // current vertex
    int &currTime                   // current time
) {
    state[u] = VIS;
    tin[u] = currTime ++;

    for(int v : a[u]) {
        if(state[v] == UNVIS) {
            printEdge(u, v, TREE);
            dfsEdgePropertyCheck(a, tin, state, v, currTime);
        }
        else if(state[v] == VIS)
            printEdge(u, v, BACK);
        else {
            if(tin[u] > tin[v])
                printEdge(u, v, CROSS);
            else
                printEdge(u, v, FORW);
        }
    }

    state[u] = EXP;
}

void edgePropertyCheck(
    const vector<vector<int> > &a
) {
    int n = a.size(), currTime = 0;
    vector<int> tin(n);
    vector<State> state(n, UNVIS);

    for(int u = 0;u < n;u++) {
        if(state[u] == UNVIS)
            dfsEdgePropertyCheck(a, tin, state, u, currTime);
    }
}

int main() {
    int t;
    cin >> t;
    
    while(t --) {
        vector<vector<int> > a;

        readInput(a);
        edgePropertyCheck(a);
    }

    return 0;
}