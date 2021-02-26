#include <iostream>
#include <algorithm>

using namespace std;

struct Frog {
    int w, l, p; // weight, jump size, pos
};

inline bool comp(const Frog &frog1, const Frog &frog2) {
    return frog1.w < frog2.w;
}

const int N = 4;
int n;
Frog frogs[N];

void read_input() {
    scanf("%d ", &n);

    for(int i = 0;i < n;i++) {
        frogs[i].p = i;
        scanf("%d ", &frogs[i].w);
    }

    for(int i = 0;i < n;i++) scanf("%d ", &frogs[i].l);
}

void solve() {
    sort(frogs, frogs + n, comp);

    int num_times = 0;
    for(int i = 1;i < n;i++) {
        if(frogs[i].p > frogs[i - 1].p) continue;

        int curr_dist = frogs[i - 1].p - frogs[i].p;
        int num_hits_req = curr_dist / frogs[i].l + 1;

        num_times += num_hits_req;
        frogs[i].p += num_hits_req * frogs[i].l;
    }

    printf("%d\n", num_times);
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
