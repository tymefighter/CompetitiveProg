#include<iostream>
#include<string>
#include<cstdio>
#include<map>


using namespace std;

int dist[51][51];
int n, M;
map<string, int> m;

void reset()
{
    int i, j;
    m.clear();
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            if(i == j)
            {
                dist[i][i] = 0;
                continue;
            }
            dist[i][j] = 100000000;
        }
    }
}

void read()
{
    string a, b;
    int ct = 0;
    for(int i = 0;i < M;i++)
    {
        cin>>a>>b;
        
        if(m.find(a) == m.end())
            m[a] = ct++;
        if(m.find(b) == m.end())
            m[b] = ct++;

        dist[m[a]][m[b]] = dist[m[b]][m[a]] = 1;
    }
}

int FW()
{
    int k, u, v;

    for(k = 0;k < n;k++)
    {
        for(u = 0;u < n;u++)
        {
            for(v = 0;v < n;v++)
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
        }
    }

    int max_val = -1;

    for(u = 0;u < n;u++)
    {
        for(v = 0;v < n;v++)
            max_val = max(max_val, dist[u][v]);
    }

    return max_val;
}

int main()
{
    int c = 1, ans;
    while(cin>>n>>M)
    {
        if(!(n|M))
            break;
        reset();
        read();
        ans = FW();
        if(ans >= 100000000)
            printf("Network %d: DISCONNECTED\n\n", c);
        else
            printf("Network %d: %d\n\n", c, ans);
        c++;
    }

    return 0;
}