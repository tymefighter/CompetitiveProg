#include <iostream>

using namespace std;

const int N = 5005, K = 5005;
const long long MOD = 1000000007;

long long dp[N][K + 1];
long long numContain[N];
int a[N];

int n, k, q;

void readInput() {
    scanf("%d %d %d ", &n, &k, &q);

    for(int i = 0;i < n;i++)
        scanf("%d ", &a[i]);
}

void computeDP() {
    for(int i = 0;i < n;i++)
        dp[i][0] = 1;

    for(int r = 1;r <= k;r++) {
        for(int i = 0;i < n;i++) {
            dp[i][r] = 0;

            if(i > 0) dp[i][r] = (dp[i][r] + dp[i - 1][r - 1]) % MOD;
            if(i < n - 1) dp[i][r] = (dp[i][r] + dp[i + 1][r - 1]) % MOD; 
        }
    }

    for(int i = 0;i < n;i++) {
        numContain[i] = 0;

        for(int r = 0;r <= k;r++)
            numContain[i] = 
                (numContain[i] + (dp[i][r] * dp[i][k - r]) % MOD) % MOD;
    }
}

void solveQueries() {
    long long result = 0;
    for(int i = 0;i < n;i++)
        result = (result + (a[i] * numContain[i]) % MOD) % MOD;

    while(q --) {
        int idx, value;
        scanf("%d %d ", &idx, &value);
        idx --;
        
        result = (result + ((value - a[idx]) * numContain[idx]) % MOD) % MOD;
        a[idx] = value;

        if(result < 0)
            result += MOD;

        printf("%lld\n", result);
    }
}

int main() {

    readInput();
    computeDP();
    solveQueries();

    return 0;
}
