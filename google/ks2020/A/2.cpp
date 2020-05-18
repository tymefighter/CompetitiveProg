#include<iostream>

using namespace std;

const int N = 55, K = 35, P = 1505;
const int INF = 100000000;
int n, k, p, a[N][K];
long long dp[N][P + 1], sum_v[N][K + 1];

void read()
{
    scanf("%d %d %d", &n, &k, &p);
    for(int i = 0;i < n;i++)
    {
        sum_v[i][0] = 0;
        for(int j = 0;j < k;j++)
        {
            scanf("%d", &a[i][j]);
            sum_v[i][j + 1] = sum_v[i][j] + a[i][j];
        }
    }
}

void solve(int case_no)
{
    for(int q = 0;q <= p;q++)
        dp[0][q] = (q > k ? -INF : sum_v[0][q]);

    for(int i = 1;i < n;i++)
    {
        for(int q = 0;q <= p;q++)
        {
            dp[i][q] = 0;
            for(int j = 0;j <= min(q, k);j++)
                dp[i][q] = max(dp[i][q], dp[i - 1][q - j] + sum_v[i][j]);
        }
    }

    printf("Case #%d: %lld\n", case_no, dp[n - 1][p]);
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int i = 1;i <= t;i++)
    {
        read();
        solve(i);
    }
    return 0;
}