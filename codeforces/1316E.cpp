#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100005;
int n, p, k;
int a[N], s[N][7];
pair<int, int> sort_order[N];
long long dp[N][128]; // 2^7 = 128

void read()
{
    scanf("%d%d%d", &n, &p, &k);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &a[i]);
        sort_order[i] = {a[i], i};
    }
    sort(sort_order, sort_order + n);
    reverse(sort_order, sort_order + n);
    
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < p;j++)
            scanf("%d", &s[i][j]);
    }
}

int num_set(int x)
{
    int val = 0;
    for(int i = 1;i <= x; i = (i << 1))
    {
        if(i & x)
            val ++;
    }
    return val;
}

void solve()
{
    for(int j = 0;j < p;j++)
        dp[0][1 << j] = s[sort_order[0].second][j];
    dp[0][0] = a[sort_order[0].second];

    for(int i = 1;i < n;i++)
    {
        for(int pos = 0;pos <= (1 << p) - 1;pos++)
        {
            dp[i][pos] = -1;
            if(num_set(pos) > i + 1)
                continue;
            for(int j = 0;j < p;j++)
            {
                if(!(pos & (1 << j)))
                    continue;
                
                dp[i][pos] = max(dp[i][pos], dp[i - 1][pos & (~(1 << j))] + (long long) s[sort_order[i].second][j]);
            }

            if((i - num_set(pos) < k) && dp[i - 1][pos] != -1 && num_set(pos) < i + 1)
                dp[i][pos] = max(dp[i][pos], dp[i - 1][pos] + (long long) a[sort_order[i].second]);
            else
                dp[i][pos] = max(dp[i][pos], dp[i - 1][pos]);

        }
    }

    printf("%lld\n", dp[n - 1][(1 << p) - 1]);
}

int main()
{
    read();
    solve();
    return 0;
}