#include<iostream>

using namespace std;

const long long MOD = 1e9 + 7;
int n, m;
long long dpa[15][1005], dpb[15][1005];

void solve()
{
    int i, j, v, x;

    for(v = 1;v <= n;v++)
    {
        dpa[0][v] = 1;
        dpb[0][v] = 1;
    }

    for(i = 1;i < m;i++)
    {
        for(v = 1;v <= n;v++)
        {
            dpa[i][v] = 0;
            for(x = 1;x <= v;x++)
                dpa[i][v] = (dpa[i][v] + dpa[i - 1][x]) % MOD;
            
            for(x = v;x <= n;x++)
                dpb[i][v] = (dpb[i][v] + dpb[i - 1][x]) % MOD;
        }
    }

    long long ans = 0;
    for(i = 1;i <= n;i++)
    {
        for(j = i;j <= n;j++)
        {
            ans = (ans + ((dpa[m - 1][i] * dpb[m - 1][j]) % MOD)) % MOD;
        }
    }

    cout<<ans<<"\n";
}

int main()
{
    cin>>n>>m;
    solve();

    return 0;
}