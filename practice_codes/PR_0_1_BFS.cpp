#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m, source;
vector<vector<pair<int, int> > > a;
vector<int> dist;

void read()
{
    scanf("%d %d", &n, &m);
    a.clear();
    a.resize(n);
    dist.clear();
    dist.assign(n, -1);

    for(int i = 0;i < m;i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        a[u].push_back({v, w});
    }

    scanf("%d", &source);
}

deque<int> dq;

void BFS_0_1()
{
    int u = source;
    dist[u] = 0;
    dq.push_back(u);

    while(!dq.empty())
    {
        u = dq.front();
        dq.pop_front();

        for(pair<int, int> v : a[u])
        {
            if(v.second == 0 && (dist[v.first] == -1 || dist[u] < dist[v.first]))
            {
                dist[v.first] = dist[u];
                dq.push_front(v.first);
            }
            else if(dist[v.first] == -1)
            {
                dist[v.first] = dist[u] + 1;
                dq.push_back(v.first);
            }
        }
    }

    for(int d : dist)
        printf("%d ", d);
    printf("\n");
}

int main()
{
    read();
    BFS_0_1();
    return 0;
}