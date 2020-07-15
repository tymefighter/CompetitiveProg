#include<iostream>
#include<vector>

using namespace std;

const int N = 100005;

int n, m, deg[N];
vector<vector<int> > a;

void readInput() {
    cin >> n >> m;
    a.clear();
    a.resize(n);
    for(int i = 0;i < n;i++)
        deg[i] = 0; 
    for(int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        a[u].push_back(v);
        a[v].push_back(u);
        deg[u] ++;
        deg[v] ++;
    }
}

bool visited[N];
vector<int> comp;

void dfs(int u) {
    visited[u] = true;
    comp.push_back(u);

    for(int v : a[u]) {
        if(!visited[v])
            dfs(v);
    }
}

int dp[2005][2005];

int solve() {
    for(int i = 0;i < n;i++)
        visited[i] = false;

    int numNonTree = 0, numTree = 0, numZeroEdgeComp = 0;
    int numExtraEdges = 0;

    for(int i = 0;i < n;i++) {
        if(!visited[i]) {
            dfs(i);
            
            int numEdges = 0, comp_size = comp.size();
            for(int u : comp)
                numEdges += deg[u];
            numEdges /= 2;

            if(numEdges >= comp_size) {
                numNonTree ++;
                numExtraEdges += numEdges - (comp_size - 1);
            }
            else {
                numTree ++;
                if(numEdges == 0)
                    numZeroEdgeComp ++;
            }
        }
    }

    if(numTree == 0)
        return 0;
    else if(numNonTree == 0)
        return 2 * (numTree - 1);
    
    numExtraEdges -= (numNonTree - 1);

    
}

int main() {

    int t;
    cin >> t;
    while(t --) {
        readInput();
        cout << solve() << " 0\n";
    }

    return 0;
}