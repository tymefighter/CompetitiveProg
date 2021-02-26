#include<iostream>
#include<vector>

using namespace std;

enum State {UNVIS, VIS, EXP};

void readInput(vector<vector<int> > &a) {
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

void printPath(int v, int u, vector<int> &pred) {
    if(v == u) {
        cout << v << " ";
        return;
    }

    printPath(v, pred[u], pred);
    cout << u << " ";
}

bool dfsCycleDet(
    const vector<vector<int> > &a,
    vector<State> &state,
    vector<int> &pred,
    int u
) {
    state[u] = VIS;

    for(int v : a[u]) {
        if(state[v] == UNVIS) {
            pred[v] = u;
            if(dfsCycleDet(a, state, pred, v))
                return true;
        }
        else if(state[v] == VIS) {
            
            printPath(v, u, pred);
            cout << v << "\n";
            return true;
        }
    }

    state[u] = EXP;
    return false;
}

void cycleDetection(
    const vector<vector<int> > &a
) {
    int n = a.size();
    vector<State> state(n, UNVIS);
    vector<int> pred(n, -1);

    for(int u = 0;u < n;u++) {
        if(dfsCycleDet(a, state, pred, u))
            return;
    }

    cout << "No cycle present\n";
}

int main() {

    vector<vector<int> > a;

    readInput(a);
    cycleDetection(a);

    return 0;
}