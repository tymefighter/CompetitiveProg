#include <iostream>
#include <queue>

using namespace std;

const int N = 305;
int n, m, a[N][N];
priority_queue<pair<int, pair<int, int> > > pq;
bool done[N][N];

void read_input() {
    scanf("%d %d ", &n, &m);

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            scanf("%d ", &a[i][j]);

            done[i][j] = false;
            pq.push({a[i][j], {i, j}});
        }
    }
}

long long solve() {

    static int ar[] = {-1, 1, 0, 0};
    static int ac[] = {0, 0, -1, 1};

    long long ans = 0;
    while(!pq.empty()) {
        pair<int, pair<int, int> > x = pq.top();
        pq.pop();

        int r = x.second.first, c = x.second.second;
        if(done[r][c]) continue;

        for(int k = 0;k < 4;k++) {
            int r_next = r + ar[k], c_next = c + ac[k];

            if(r_next < 0 || r_next >= n 
                || c_next < 0 || c_next >= m) continue;

            if(a[r_next][c_next] < a[r][c] - 1) {
                ans += (a[r][c] - 1) - a[r_next][c_next];
                a[r_next][c_next] = a[r][c] - 1;

                pq.push({a[r_next][c_next], {r_next, c_next}});
            }
        }

        done[r][c] = true;
    }

    return ans;
}

int main() {

    int t;
    scanf("%d ", &t);

    for(int i = 1;i <= t;i++) {
        read_input();
        printf("Case #%d: %lld\n", i, solve());
    }

    return 0;
}