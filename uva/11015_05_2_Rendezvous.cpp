#include<iostream>

using namespace std;

const long long INF = 10000000000000;
int n, m;
long long dist[25][25];
string s[25];

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
    for(int i = 0;i < n;i++)
        cin>>s[i];

    int u, v, w;
    for(int i = 0;i < m;i++)
    {
        cin>>u>>v>>w;
        u --, v --;
        dist[u][v] = dist[v][u] = w;
    }
}

void solve(int cno)
{
    int k, i, j;

    for(k = 0;k < n;k++)
    {
        for(i = 0;i < n;i++)
        {
            for(j = 0;j < n;j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }

    int ans = -1;
    long long ans_val, val;
    for(i = 0;i < n;i++)
    {
        val = 0;
        for(j = 0;j < n;j++)
            val += dist[j][i];

        if(ans == -1 || val < ans_val)
        {
            ans = i;
            ans_val = val;
        }
    }

    printf("Case #%d : ", cno);
    cout<<s[ans]<<"\n";
}

int main()
{
    int cno = 1;
    while(cin>>n>>m)
    {
        if(!(n | m))
            break;
        reset();
        read();
        solve(cno);
        cno ++;
    }
    return 0;
}