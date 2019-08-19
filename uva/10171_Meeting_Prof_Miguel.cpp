#include<cstdio>
#include<map>
#include<iostream>
#include<algorithm>
#define VAL 100000000

using namespace std;

int dist1[26][26], dist2[26][26];
char remap[26], aval[26];
int n, M, s, e;
map<char, int> m;

void reset()
{
    m.clear();
    int i, j;
    for(i = 0;i < 26;i++)
    {
        for(j = 0;j < 26;j++)
            dist1[i][j] = dist2[i][j] = VAL;
    }
}

void read()
{
    char yny, ubi, a, b; // yny: young/non-young, ubi: unidirectional, bidirectional
    int ct = 0, w;
    for(int i = 0;i < M;i++)
    {
        scanf("%c %c %c %c %d ", &yny, &ubi, &a, &b, &w);

        if(m.find(a) == m.end())
        {
            remap[ct] = a;
            m[a] = ct++;
        }
        if(m.find(b) == m.end())
        {
            remap[ct] = b;
            m[b] = ct++;
        }

        if(yny == 'Y')
        {
            if(ubi == 'U')
                dist1[m[a]][m[b]] = w;
            else if(ubi == 'B')
                dist1[m[a]][m[b]] = dist1[m[b]][m[a]] =  w;
        }
        else if(yny == 'M')
        {
            if(ubi == 'U')
                dist2[m[a]][m[b]] = w;
            else if(ubi == 'B')
                dist2[m[a]][m[b]] = dist2[m[b]][m[a]] =  w;
        }
    }

    scanf("%c %c", &a, &b);
    if(m.find(a) == m.end())
        m[a] = ct++;
    if(m.find(b) == m.end())
        m[b] = ct++;

    s = m[a], e = m[b];

    n = m.size();
    for(int i = 0;i < n;i++)
        dist1[i][i] = dist2[i][i] = 0;
}

void FW()
{
    int u, v, k;

    for(k = 0;k < n;k++)
    {
        for(u = 0;u < n;u++)
        {
            for(v = 0;v < n;v++)
            {
                dist1[u][v] = min(dist1[u][v], dist1[u][k] + dist1[k][v]);
                dist2[u][v] = min(dist2[u][v], dist2[u][k] + dist2[k][v]);
            }
        }
    }

    int ans = VAL, val, loc = -1;

    for(u = 0;u < n;u++)
    {
        if(dist1[s][u] < VAL && dist2[e][u] < VAL)
        {
            val = dist1[s][u] + dist2[e][u];
            if(val < ans)
            {
                ans = val;
                loc = u;
            }
        }
    }

    if(loc == -1)
    {
        printf("You will never meet.\n");
        return;
    }

    int ct = 0;

    for(u = 0;u < n;u++)
    {
        if(ans == dist1[s][u] + dist2[e][u])
            aval[ct++] = remap[u];
    }
    
    sort(aval, aval + ct);
    printf("%d", ans);

    for(int i = 0;i < ct;i++)
        cout<<" "<<aval[i];
    cout<<"\n";
}

int main()
{
    while(scanf("%d ", &M) == 1)
    {
        if(!M)
            break;

        reset();
        read();
        FW();
    }
    return 0;
}