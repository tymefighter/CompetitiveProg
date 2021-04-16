#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100;
int n, c;
int cost[N - 1], p[N], a[N];

bool solve() {
    if(c < n - 1 || c >= (n * (n + 1)) / 2) return false;

    int curr_cost = c;
    for(int i = 0;i < n - 1;i++) {
        cost[i] = min(curr_cost, n - i);

        if(cost[i] == curr_cost) {
            int val_remove = n - i - 2;
            cost[0] -= val_remove;

            for(int j = i + 1;j < n - 1;j++) cost[j] = 1;

            break;
        }
        else curr_cost -= cost[i];
    }

    for(int i = 0;i < n;i++)
        p[i] = i;

    for(int i = 0;i < n - 1;i++) {
        a[p[i + cost[i] - 1]] = i + 1;
        reverse(p + i, p + i + cost[i]);
    }
    a[p[n - 1]] = n;

    return true;
}

int main() {

    int t;
    scanf("%d ", &t);

    for(int tc = 1;tc <= t;tc++) {
        scanf("%d %d ", &n, &c);


        printf("Case #%d: ", tc);
        if(solve()) {
            for(int i = 0;i < n;i++) 
                printf("%d ", a[i]);

            printf("\n");
        }
        else 
            printf("IMPOSSIBLE\n");
    }

    return 0;
}