#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

const int N = 500005;

vector<vector<int> > adj;
int l, timer;
vector<int> tin, tout;
vector<vector<int> > up;

int n, a, b, p[N], deg[N];
bool visited[N];
long long dp1[N], dp2[N];

void readInput() {
    scanf("%d %d %d ", &n, &a, &b);
    adj.clear();
    adj.resize(n);
    p[0] = -1;

    for(int i = 0;i < n;i++)
        deg[i] = 0;

    for(int i = 1;i < n;i++) {
        scanf("%d ", &p[i]);
        p[i] --;

        adj[i].push_back(p[i]);
        adj[p[i]].push_back(i);

        deg[i] ++;
        deg[p[i]] ++;
    }
}

void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = (up[v][i-1] == -1 ? -1 : up[up[v][i-1]][i-1]);

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

void computeUP() {
    tin.clear();
    tin.resize(n);
    tout.clear();
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.clear();
    up.assign(n, vector<int>(l + 1));
    dfs(0, -1);
}

int getAnc(int u, int dist) {
    if(dist == 0)
        return u;

    int j = static_cast<int>(log2((double)dist));
    int v = up[u][j];

    if(v == -1)
        return -1;
    else
        return getAnc(v, dist - (1 << j));
}

void computeDP() {
    queue<int> q;

    for(int i = 0;i < n;i++) {
        dp1[i] = dp2[i] = 1;
        visited[i] = false;
        if(i > 0 && deg[i] == 1) {
            visited[i] = true;
            q.push(i);
        }
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        int anc1 = getAnc(u, a);
        if(anc1 != -1)
            dp1[anc1] += dp1[u];

        int anc2 = getAnc(u, b);
        if(anc2 != -1)
            dp2[anc2] += dp2[u];

        if(p[u] != -1) {
            if(!visited[p[u]]) {
                visited[p[u]] = true;
                q.push(p[u]);
            }
        }
    }
}

double solve() {
    double ans = 0;
    for(int i = 0;i < n;i++) {
        double val1 = dp1[i] / (double) n, val2 = dp2[i] / (double) n;
        ans += val1;
        ans += val2;
        ans -= val1 * val2;
    }

    return ans;
}

int main() {
    int t;
    scanf("%d ", &t);
    for(int i = 1;i <= t;i++) {
        readInput();
        printf("Case #%d: ", i);
        if(n > 1) {
            computeUP();
            computeDP();
            cout << solve() << "\n";
        }
        else
            cout << "1\n";
    }
    return 0;
}