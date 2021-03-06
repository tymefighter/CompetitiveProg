#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, r, m;
vector<vector<int> > a;
vector<int> city_soldier;

void read_input() {

    scanf("%d %d %d ", &n, &r, &m);

    a.clear();
    a.resize(n);
    city_soldier.clear();
    city_soldier.assign(n, -1);

    while(r --) {
        int u, v;
        scanf("%d %d ", &u, &v);
        u --, v --;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

bool check_soldier(int s, int d, int soldier) {
    queue<pair<int, int> > q;

    if(city_soldier[s] != -1) return false;

    city_soldier[s] = soldier;
    q.push({s, d});

    while(!q.empty()) {
        int u = q.front().first;
        int dist_left = q.front().second;
        q.pop();

        if(dist_left == 0) continue;

        for(int v : a[u]) {

            if(city_soldier[v] == -1) {
                city_soldier[v] = soldier;
                q.push({v, dist_left - 1});
            }
            else if(city_soldier[v] != soldier)
                return false;
        }
    }

    return true;
}

void solve() {
    bool is_optimum = true;
    
    for(int soldier = 0;soldier < m;soldier ++) {
        int k, s;
        scanf("%d %d ", &k, &s);
        k --;

        if(is_optimum) is_optimum = check_soldier(k, s, soldier);
    }

    for(int i = 0;i < n;i++)
        is_optimum &= (city_soldier[i] != -1);

    if(is_optimum) printf("Yes\n");
    else printf("No\n");
}

int main() {

    int t;
    scanf("%d ", &t);

    while(t --) {
        read_input();
        solve();
    }

    return 0;
}