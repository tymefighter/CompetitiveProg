#include<iostream>
#include<cmath>

using namespace std;

int n, l, r, t;

int extended_euclid(int a, int b, long long &x, long long &y)
{
    if(a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }

    long long x1, y1;
    int g;
    g = extended_euclid(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;
    return g;
}

void solve()
{
    long long xg, yg;
    int g;
    g = extended_euclid(r, l, xg, yg);

    if(g < 0)
    {
        g = -g;
        xg = -xg;
        yg = -yg;
    }

    int val = t - 1;
    xg *= val / g;
    yg *= val / g;

    if(val % g != 0)
    {
        cout<<"uh-oh!\n";
        return;
    }
    
    r /= g;
    l /= g;

    long long k = max(ceil(-xg / (double)l), ceil(yg / (double)r));
    k = max(k, 0ll);

    long long ans = xg - yg + (r + l) * k;
    cout<<ans<<"\n";
}

int main()
{
    int c;
    cin>>c;
    while(c--)
    {
        cin>>n>>l>>r>>t;
        solve();
    }
    return 0;
}

/*
#include<iostream>
#include<queue>

using namespace std;

int n, l, r, t;
int dist[10000005];
queue<int> q;

void reset()
{
    for(int i = 0;i <= n;i++)
        dist[i] = -1;
    while(!q.empty())
        q.pop();
}

void bfs()
{
    dist[1] = 0;
    q.push(1);

    int u, v;

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        v = u + r;
        if(v <= n && dist[v] == -1)
        {
            dist[v] = dist[u] + 1;
            if(v == t)
                return;
            q.push(v);
        }
        v = u - l;
        if(v > 0 && dist[v] == -1)
        {
            dist[v] = dist[u] + 1;
            if(v == t)
                return;
            q.push(v);
        }
    }
}

int main()
{
    int c;
    scanf("%d", &c);

    while(c--)
    {
        scanf("%d %d %d %d", &n, &l, &r, &t);
        reset();
        bfs();
        if(dist[t] == -1)
            cout<<"uh-oh!\n";
        else
            cout<<dist[t]<<"\n";
    }
    return 0;
}
*/