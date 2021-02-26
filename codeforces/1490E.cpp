#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200000;
int n;
pair<int, int> a[N];
bool can_win[N];

int main() {

    int t;
    scanf("%d ", &t);

    while(t --) {
        int n;
        scanf("%d ", &n);

        for(int i = 0;i < n;i++) {
            scanf("%d ", &a[i].first);
            a[i].second = i;

            can_win[i] = true;
        }

        sort(a, a + n);
        long long prefix_sum = a[0].first;
        int fail_idx = -1;

        for(int i = 1;i < n;i++) {
            if(prefix_sum < a[i].first) fail_idx = i - 1;

            prefix_sum += a[i].first;
        }

        for(int j = 0;j <= fail_idx;j++)
            can_win[a[j].second] = false;

        printf("%d\n", n - fail_idx - 1);
        for(int i = 0;i < n;i++)
            if(can_win[i]) printf("%d ", i + 1);

        printf("\n");
    }


    return 0;
}