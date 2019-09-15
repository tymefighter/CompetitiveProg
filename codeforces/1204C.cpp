#include<iostream>
#include<vector>

using namespace std;

int n, m;
int dist[105][105];
int a[1000005];
const int INF = 100000000;

void read()
{
    cin>>n;
    int i, j;
    char x;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            cin>>x;
            dist[i][j] = (x == '1' ? 1 : INF);
        }

        dist[i][i] = 0;
    }

    cin>>m;
    for(i = 0;i < m;i++)
    {
        cin>>a[i];
        a[i] --;
    }
}

void FW()
{
    int i, j, k;

    for(k = 0;k < n;k++)
    {
        for(i = 0;i < n;i++)
        {
            for(j = 0;j < n;j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void solve()
{
    int u, v, len;
    vector<int> ans;

    u = a[0];
    ans.push_back(u + 1);
    len = 1;

    for(int i = 1;i < m;i++)
    {
        v = a[i];
        if(dist[u][v] != len)
        {
            i --;
            u = a[i];
            ans.push_back(u + 1);
            len = 0;
        }
        len ++;
    }

    ans.push_back(v + 1);

    cout<<ans.size()<<"\n";
    for(int x : ans)
        cout<<x<<" ";
    cout<<"\n";
}

int main()
{
    read();
    FW();
    solve();

    return 0;
}