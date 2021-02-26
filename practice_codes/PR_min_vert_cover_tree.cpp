#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void readInput(vector<vector<int> > &a) {
    int n;
    cin >> n;
    a.clear();
    a.resize(n);

    for(int i = 0;i < n - 1;i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

int computeDP(
    const vector<vector<int> > &a,
    vector<vector<int> > &dp,
    vector<vector<vector<pair<int, int> > > > &pred,
    int u,
    int takeVert,
    int parent
) {
    if(dp[u][takeVert] != -1)
        return dp[u][takeVert];

    if(takeVert == 0) {
        dp[u][takeVert] = 0;
        for(int v : a[u]) {
            if(v == parent)
                continue;

            dp[u][takeVert] += computeDP(a, dp, pred, v, 1, u);
            pred[u][takeVert].push_back({v, 1});
        }
    }
    else {
        dp[u][takeVert] = 1;
        for(int v : a[u]) {
            if(v == parent)
                continue;

            int valTake = computeDP(a, dp, pred, v, 1, u);
            int valNotTake  = computeDP(a, dp, pred, v, 0, u);

            if(valTake < valNotTake) {
                dp[u][takeVert] += valTake;
                pred[u][takeVert].push_back({v, 1});
            }
            else {
                dp[u][takeVert] += valNotTake;
                pred[u][takeVert].push_back({v, 0});
            }
        }
    }

    return dp[u][takeVert];
}

void mvc(const vector<vector<int> > &a, vector<int> &verts) {
    int n = a.size();
    vector<vector<int> > dp(n, vector<int>(2, -1));
    vector< vector< vector< pair<int, int> > > > pred (
        n,
        vector<vector<pair<int, int> > > (
            2,
            vector<pair<int, int> > ()
        )
    );

    int valTakeRoot = computeDP(a, dp, pred, 0, 1, -1);
    int valNotTakeRoot = computeDP(a, dp, pred, 0, 0, -1);

    queue<pair<int, int> > q;
    if(valTakeRoot < valNotTakeRoot)
        q.push({0, 1});
    else
        q.push({0, 0});

    while(!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();

        if(u.second == 1)
            verts.push_back(u.first);

        for(pair<int, int> v : pred[u.first][u.second])
            q.push(v);
    }
}

void printOutput(const vector<int> &verts) {
    cout << "Number of verts: " << verts.size() << "\n";
    for(int u : verts)
        cout << u << " ";
    cout << "\n"; 
}

int main() {

    vector<vector<int> > a;
    vector<int> verts;
    
    readInput(a);
    mvc(a, verts);
    printOutput(verts);

    return 0;
}