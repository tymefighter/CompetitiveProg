#include<iostream>
#include<vector>

using namespace std;

const long long INF = 10000000000000000;
int n, a[100005];
pair<int, int> p[100005][2];
long long dp[100005][2];

void read()
{
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        p[i][0] = p[i][1] = {-1, -1};
    }
}

void solve()
{
    if(n == 1)
    {
        cout<<a[0]<<" 1\n";
        cout<<"0\n";
        return;
    }
    dp[0][0] = a[0];
    dp[0][1] = -INF;
    dp[1][0] = a[0] + a[1];
    p[1][0] = {0, 0};
    dp[1][1] = a[0] * a[1];

    for(int i = 2;i < n;i++)
    {
        long long val1, val2;

        val1 = dp[i - 2][0] + a[i - 1] * a[i];
        val2 = dp[i - 2][1] + a[i - 1] * a[i];
        if(val1 >= val2)
        {
            dp[i][1] = val1;
            p[i][1] = {i - 2, 0};
        }
        else
        {
            dp[i][1] = val2;
            p[i][1] = {i - 2, 1};
        }

        val1 = dp[i - 1][0] + a[i];
        val2 = dp[i - 1][1] + a[i];
        if(val1 >= val2)
        {
            dp[i][0] = val1;
            p[i][0] = {i - 1, 0};
        }
        else
        {
            dp[i][0] = val2;
            p[i][0] = {i - 1, 1};
        }

        // dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + a[i - 1] * a[i];
        // dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];
    }

    vector<pair<int, int> > id_pair;
    pair<int, int> pr;
    int i, b;

    if(dp[n - 1][1] >= dp[n - 1][0])
    {
        cout<<dp[n - 1][1]<<" ";
        i = n - 1, b = 1;
    }
    else
    {
        cout<<dp[n - 1][0]<<" ";
        i = n - 1, b = 0;
    }

    while(i != -1)
    {
        pr = p[i][b];

        if(b == 1)
            id_pair.push_back({i, i + 1});

        i = pr.first;
        b = pr.second;
    }

    cout<<n - id_pair.size()<<"\n";
    cout<<id_pair.size()<<"\n";
    for(auto e : id_pair)
        cout<<e.first<<" "<<e.second<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        read();
        solve();
    }
    return 0;
}