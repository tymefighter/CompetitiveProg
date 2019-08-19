#include<iostream>
#include<utility>
#include<queue>
#include<vector>

using namespace std;

int n, m;
int a[1001][1001];
int dist[1001][1001];
int ar[4] = {0, 0, -1, 1};
int ac[4] = {-1, 1, 0, 0};
priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq; 

void read()
{
    cin>>n>>m;
    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            cin>>a[i][j];
            dist[i][j] = -1;
        }
    }
}

bool check(int r, int c)
{
    if(r < 0 || r >= n || c < 0 || c >= m)
        return false;
    
    return true;
}

int Dijkstra()
{
    dist[0][0] = a[0][0];
    pq.push({0, {0, 0}});
    pair<int, pair<int, int> > x;
    int d, r, c, i, rd, cd;

    while(!pq.empty())
    {
        x = pq.top(), pq.pop();
        d = x.first, r = x.second.first, c = x.second.second;
        if(d > dist[r][c])  // lazy deletion
            continue;
        
        for(i = 0;i < 4;i++)
        {
            rd = r + ar[i], cd = c + ac[i];
            if(!check(rd, cd))
                continue;
            
            if(dist[rd][cd] == -1 || dist[r][c] + a[rd][cd] < dist[rd][cd])
            {
                dist[rd][cd] = dist[r][c] + a[rd][cd];
                pq.push({dist[rd][cd], {rd, cd}});
            }
        }
    }

    return dist[n-1][m-1];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        read();
        cout<<Dijkstra()<<"\n";
    }

    return 0;
}