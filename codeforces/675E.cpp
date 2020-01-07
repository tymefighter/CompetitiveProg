#include<iostream>
#include<cmath>

using namespace std;

const int N = 100005;
int n, a[N];
pair<int, int> st[N][20]; // sparse table stores (value, idx)
long long dp[N];

void build_st()
{
    int i, j;
    for(i = 0;i < n;i++)
        st[i][0] = {a[i], i};
    
    for(j = 1;(1 << j) <= n;j++)
    {
        for(i = 0;i + (1 << j) <= n;i++)
        {
            if(st[i][j - 1].first > st[i + (1 << (j - 1))][j - 1].first)
                st[i][j] = st[i][j - 1];
            else
                st[i][j] = st[i + (1 << (j - 1))][j - 1];
        }
    }
}

int getMaxIndex(int l, int r)
{
    int j = (int)log2(r - l + 1);

    if(st[l][j] > st[r - (1 << j) + 1][j])
        return st[l][j].second;
    else
        return st[r - (1 << j) + 1][j].second;
}

void read()
{
    cin>>n;
    for(int i = 0;i < n - 1;i++)
    {
        cin>>a[i];
        a[i] --;
    }
    a[n - 1] = n - 1;

    build_st();
}

void solve()
{
    dp[n - 1] = 0;
    long long dp_sum = 0;

    for(int i = n - 2;i >= 0;i--)
    {
        int j0 = getMaxIndex(i, a[i]);
        dp[i] = (n - i - 1) + dp[j0] - (a[i] - j0);
        dp_sum += dp[i];
    }

    cout<<dp_sum<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}