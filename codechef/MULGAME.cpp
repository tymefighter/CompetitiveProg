#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200000;
int n, q, m, a[N];
int num_wins[N + 2];
pair<int, int> queries[N];

void read_input() {
    scanf("%d %d %d ", &n, &q, &m);
        for(int i = 0;i < n;i++) scanf("%d ", &a[i]);

    for(int i = 0;i < q;i++) {
        scanf("%d %d ", &queries[i].first, &queries[i].second);
        queries[i].first --;
        queries[i].second --;
    }
}

void solve() {
    for(int i = 0;i <= m;i++) num_wins[i] = 0;

    sort(queries, queries + q);
    int update_value = 0;

    for(int i = 0;i < q;i++) {
        update_value ++;
        if(i + 1 < q && queries[i] == queries[i + 1]) continue;

        int left_val = a[queries[i].first], right_val = a[queries[i].second];
        int min_range = left_val;
        int max_range = min_range + right_val - 1;

        while(min_range <= m) {
            num_wins[min_range] += update_value;
            num_wins[min(max_range, m) + 1] -= update_value;

            min_range = max_range + left_val + 1;
            max_range = min_range + right_val - 1;
        }

        update_value = 0;
    }

    int max_wins = num_wins[0];
    for(int i = 1;i <= m;i++) {
        num_wins[i] += num_wins[i - 1];
        max_wins = max(max_wins, num_wins[i]);
    }

    printf("%d\n", max_wins);
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