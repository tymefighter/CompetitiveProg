#include<iostream>
#include<map>
#include<cstdio>

using namespace std;

int dist[105][105];
int n;
map<int, int> m;

int a, b;

void reset()
{
    m.clear();
    int i, j;
    for(i = 0;i < 105;i++)
    {
        for(j = 0;j < 105;j++)
            dist[i][j] = 100000000;
    }
}

void read()
{
    m[a] = 0;
    m[b] = 1;
    int ct = 2;
    dist[0][1] = 1;

    while(cin>>a>>b)
    {
        if(!(a|b))
            break;
        if(m.find(a) == m.end())
            m[a] = ct++;
        if(m.find(b) == m.end())
            m[b] = ct++;

        dist[m[a]][m[b]] = 1;
    }

    n = m.size();

    for(int u = 0;u < n;u++)
        dist[u][u] = 0;

}

float FW()
{
    int u, v, k;
    for(k = 0;k < n;k++)
    {
        for(u = 0;u < n;u++)
        {
            for(v = 0;v < n;v++)
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
        }
    }

    int ans = 0;
    for(u = 0;u < n;u++)
    {
        for(v = 0;v < n;v++)
        {
            if(u == v)
                continue;

            ans += dist[u][v];
        }
    }

    return (float)ans / (float)(n*n - n);
}

int main()
{
    int c = 1;
    while(cin>>a>>b)
    {
        if(!(a|b))
            break;
        reset();
        read();
        printf("Case %d: average length between pages = %0.3f clicks\n", c, FW());
        c++;
    }

    return 0;
}