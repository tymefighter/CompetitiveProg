#include <iostream>
#include <queue>

using namespace std;

const int N = 100;
int n, m, a[N][N];
int water_level[N][N];

void read_input() {
    scanf("%d %d ", &n, &m);

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            scanf("%d ", &a[i][j]);
    }
}

priority_queue<pair<int, pair<int, int> >, 
    vector<pair<int, pair<int, int> > >,
    greater<pair<int, pair<int, int> > > > pq;

inline void clear_queue() {
    while(!pq.empty()) pq.pop();
}

void add_boundary() {
    for(int i = 0;i < n;i++) {
        pq.push({a[i][0], {i, 0}});
        pq.push({a[i][m - 1], {i, m - 1}});
    }

    for(int j = 0;j < m;j++) {
        pq.push({a[0][j], {0, j}});
        pq.push({a[n - 1][j], {n - 1, j}});
    }
}

int ai[] = {-1, 1, 0, 0};
int aj[] = {0, 0, -1, 1};

inline bool is_valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void set_water_level(int i, int j, int level) {
    water_level[i][j] = level;

    for(int k = 0;k < 4;k++) {
        int next_i = i + ai[k], next_j = j + aj[k];
        if(is_valid(next_i, next_j)) {
            if(a[next_i][next_j] <= level
            && water_level[next_i][next_j] == -1)
                set_water_level(next_i, next_j, level);
            else if(a[next_i][next_j] > level)
                pq.push({a[next_i][next_j], {next_i, next_j}});
        }
    }
}

void solve() {
    clear_queue();
    add_boundary();

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            water_level[i][j] = -1;
    }

    while(!pq.empty()) {
        int level = pq.top().first;
        int i = pq.top().second.first, j = pq.top().second.second;
        pq.pop();

        if(water_level[i][j] == -1) set_water_level(i, j, level);
    }

    int volume = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            volume += water_level[i][j] - a[i][j];
    }

    printf("%d\n", volume);
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