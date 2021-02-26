#include<iostream>
#include<vector>

using namespace std;

void readInput(vector<vector<bool> > &reach) {
    int n, m;
    cin >> n >> m;
    reach.clear();
    reach.assign(n, vector<bool>(n, false));

    for(int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v;
        reach[u][v] = true;
    }

    for(int i = 0;i < n;i++)
        reach[i][i] = true;
}

void transitiveClosure(vector<vector<bool> > &reach) {
    int n = reach.size();
    for(int k = 0;k < n;k++) {
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                reach[i][j] = reach[i][j] | (reach[i][k] & reach[k][j]);
            }
        }
    }
}

void printOutput(const vector<vector<bool> > &reach) {
    int n = reach.size();
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++)
            cout
                << i 
                << " "
                << j
                << ", "
                << (reach[i][j] ? "Reachable" : "Not Reachable")
                << "\n";
    }
}

int main() {

    vector<vector<bool> > reach;

    readInput(reach);
    transitiveClosure(reach);
    printOutput(reach);

    return 0;
}