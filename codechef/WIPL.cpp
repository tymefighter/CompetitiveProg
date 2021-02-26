#include <iostream>
#include <algorithm>

using namespace std;

const int N = 4000;
int n, k, h[N];
int prefixSum[N];
bool dp[N][N];

int solve() {
    sort(h, h + n, greater<int>());

    if(h[0] >= k) {
        int numBoxes = 1;
        while(numBoxes < n && k > 0)
            k -= h[numBoxes ++];

        return k <= 0 ? numBoxes : -1;
    }

    dp[0][0] = dp[0][h[0]] = true;
    prefixSum[0] = h[0];

    for(int i = 1;i < n;i++) {
        prefixSum[i] = prefixSum[i - 1] + h[i];

        for(int j = 0;j < k;j++) {
            dp[i][j] = dp[i - 1][j];
            if(j >= h[i]) dp[i][j] |= dp[i - 1][j - h[i]];

            if(dp[i - 1][j] && j + h[i] >= k && prefixSum[i] - (j + h[i]) >= k)
                return i + 1;
        }
    }

    return -1;
}

int main() {

    int t;
    scanf("%d ", &t);

    while(t --) {
        scanf("%d %d ", &n, &k);
        for(int i = 0;i < n;i++)
            scanf("%d ", &h[i]);

        printf("%d\n", solve());
    }

    return 0;
}
