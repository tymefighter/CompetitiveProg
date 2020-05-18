#include <iostream>

using namespace std;

const int N = 1000005;
int dp[N];

void init_dp() {
    for(int i = 0;i < N;i++)
        dp[i] = -1;
}

int computeDP(int n) {

    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else if(dp[n] != -1)
        return dp[n];

    int ans = -1, val;
    for(int i = 2;i * i <= n;i++) {

        if(n % i == 0) {
            val = computeDP(n / i);
            if(ans == -1 || val < ans)
                ans = val;
        }
    }

    val = computeDP(n - 1);
    if(ans == -1 || val < ans)
        ans = val;

    dp[n] = ans + 1;
    return dp[n];
}

int main() {

    int q, n;
    init_dp();

    cin >> q;
    while(q -- ) {
        cin >> n;
        cout << computeDP(n) << "\n";
    }

    return 0;
}