#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N = 100005;
int n, m, s;
vector<vector<int> > a;
int dist[N][2];

void reset()
{
    a.clear();
    a.resize(n);
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < 2;j++)
            dist[i][j] = -1;
    }
}

void read()
{
    scanf("%d %d", &n, &m);
    reset();
    
    for(int i = 0;i < m;i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
    }
    scanf("%d", &s);
}

queue<pair<int, int> > q;

void BFS()
{
    q.push({s, 0});
    dist[s][0] = 0;

    while(!q.empty())
    {
        pair<int, int> u = q.front();
        q.pop();

        for(int v : a[u.first])
        {
            if(dist[v][1 - u.second] == -1)
            {
                dist[v][1 - u.second] = dist[u.first][u.second] + 1;
                q.push({v, 1 - u.second});
            }
        }
    }

    printf("Length of shortest even lenght path: -\n");
    for(int i = 0;i < n;i++)
        printf("%d ", dist[i][0]);
    printf("\n");

    printf("Length of shortest odd lenght path: -\n");
    for(int i = 0;i < n;i++)
        printf("%d ", dist[i][1]);
    printf("\n");
}

int main()
{
    read();
    BFS();
    return 0;
}
