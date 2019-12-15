#include<iostream>

using namespace std;

const int INF = 100000000;
int n, dist[105][105];

string s;

void reset()
{
    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
            dist[i][j] = INF;
        dist[i][i] = 0;
    }
}

void read()
{
    int i, j;

    for(i = 1;i < n;i++)
    {
        for(j = 0;j < i;j++)
        {
            cin>>s;
            if(s == "x")
                continue;
            dist[j][i] = dist[i][j] = stoi(s);
        }
    }
}

void solve()
{
    int k, i, j;

    for(k = 0;k < n;k++)
    {
        for(i = 0;i < n;i++)
        {
            for(j = 0;j < n;j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[j][k]);
        }
    }

    int ans = -1;
    for(j = 0;j < n;j++)
        ans = max(ans, dist[0][j]);
    cout<<ans<<"\n";
}

int main()
{
    while(cin >> n)
    {
        reset();
        read();
        solve();
    }
    return 0;
}