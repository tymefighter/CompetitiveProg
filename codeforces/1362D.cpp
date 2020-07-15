#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<vector<int> > a;
vector<pair<int, int> > t; // (val, node number)
vector<int> val_assigned;

void reset() {
    a.clear();
    a.resize(n);
    t.clear();
    t.resize(n);
    val_assigned.clear();
    val_assigned.assign(n, 0);
}

void readInput() {
    scanf("%d %d ", &n, &m);

    reset();

    for(int i = 0;i < m;i++) {
        int u, v;
        scanf("%d %d ", &u, &v);
        u --, v --;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for(int i = 0;i < n;i++) {
        scanf("%d ", &t[i].first);
        t[i].second = i;
    }
}

bool solve() {
    sort(t.begin(), t.end());

    vector<bool> covered(n + 1, false);

    for(const pair<int, int> &p : t) {
        int u = p.second;
        
        for(int v : a[u])
            covered[val_assigned[v]] = true;

        for(int i = 1;i <= n;i++) {
            if(!covered[i]) {
                val_assigned[u] = i;
                break;
            }
        }

        if(val_assigned[u] != p.first)
            return false;

        for(int v : a[u])
            covered[val_assigned[v]] = false;
    }

    return true;
}

int main() {

    readInput();
    if(solve()) {
        for(const pair<int, int> &p : t)
            printf("%d ", p.second + 1);
        printf("\n");
    }
    else
        printf("-1\n");
    return 0;
}