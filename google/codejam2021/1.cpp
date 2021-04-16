#include <iostream>
#include <algorithm>

using namespace std;

const int N = 105;
int a[N];

int main() {

    int t;
    scanf("%d ", &t);

    for(int tc = 1;tc <= t;tc++) {
        int n;
        scanf("%d ", &n);

        for(int i = 0;i < n;i++) scanf("%d ", &a[i]);

        int cost = 0;
        for(int i = 0;i < n - 1;i++) {

            int min_idx = i;
            for(int j = i;j < n;j++)
                if(a[j] < a[min_idx]) min_idx = j;

            cost += min_idx - i + 1;
            reverse(a + i, a + min_idx + 1);
        }

        printf("Case #%d: %d\n", tc, cost);
    }

    return 0;
}