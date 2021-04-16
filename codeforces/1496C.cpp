#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 100000;
int n, miner[N], mine[N];

void read_input() {
    scanf("%d ", &n);

    int idx_miner = 0, idx_mine = 0;
    for(int i = 0;i < (n << 1);i++) {
        int x, y;
        scanf("%d %d ", &x, &y);

        if(x == 0) miner[idx_miner ++] = abs(y);
        else mine[idx_mine ++] = abs(x);
    }

    sort(miner, miner + n);
    sort(mine, mine + n);
}

inline double norm(double x, double y) {return sqrt(x * x + y * y);}

void solve() {
    double min_energy = 0;
    for(int i = 0;i < n;i++)
        min_energy += norm(mine[i], miner[i]);

    printf("%.15lf\n", min_energy);
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