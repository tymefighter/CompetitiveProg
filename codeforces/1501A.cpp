#include <iostream>

using namespace std;

const int N = 100;
int n, a[N], b[N], tm[N];

void read_input() {
    scanf("%d ", &n);
    for(int i = 0;i < n;i++) scanf("%d %d ", &a[i], &b[i]);
    for(int i = 0;i < n;i++) scanf("%d ", &tm[i]);
}

int ceil_div(int x, int y) {return (x + y - 1) / y;}

void solve() {
    int curr_time = a[0] + tm[0];

    for(int i = 0;i < n - 1;i++) {
        int prev_time = curr_time;
        curr_time = max(curr_time, b[i]);

        int spent_time = max(curr_time - prev_time, 0);
        int req_time = ceil_div(b[i] - a[i], 2);
        if(spent_time <= req_time)
            curr_time += req_time - spent_time;

        curr_time += a[i + 1] - b[i] + tm[i + 1];
    }

    printf("%d\n", curr_time);
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