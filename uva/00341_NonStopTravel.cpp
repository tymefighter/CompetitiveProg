#include<iostream>

using namespace std;

const int INF = 100000000;
int n, s, t, dist[15][15], p[15][15];

void reset()
{
    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            dist[i][j] = INF;
            p[i][j] = -1;
        }
    }
}

void read()
{
    int i, j, v, w, m;
    for(i = 0;i < n;i++)
    {
        cin>>m;
        for(j = 0;j < m;j++)
        {
            cin>>v>>w;
            v --;
            dist[i][v] = min(dist[i][v], w);
        }
    }

    cin>>s>>t;
    s --, t --;
}

void printPath(int i, int j)
{
    if(j == i)
    {
        cout<<i + 1;
        return;
    }

    printPath(i, p[i][j]);
    cout<<" "<<j + 1;
}

void FW(int cno)
{
    int k, i, j;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            if(dist[i][j] != INF)
                p[i][j] = i;
        }
    }

    for(k = 0;k < n;k++)
    {
        for(i = 0;i < n;i++)
        {
            for(j = 0;j < n;j++)
            {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
    }

    printf("Case %d: Path = ", cno);
    printPath(s, t);
    printf("; %d second delay\n", dist[s][t]);
}

int main()
{
    int cno = 1;
    while(cin>>n)
    {
        if(!n)
            break;
        reset();
        read();
        FW(cno);
        cno ++;
    }
    return 0;
}