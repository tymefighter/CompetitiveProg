#include<iostream>
#include<cmath>
#include<queue>

using namespace std;

const int N = 105;

int n;
pair<double, double> pts[N];
double a[N][N];
bool taken[N];

double dist(const pair<double, double> &a, const pair<double, double> &b)
{
    double val = (a.first - b.first) * (a.first - b.first);
    val += (a.second - b.second) * (a.second - b.second);
    return sqrt(val);
}

void reset()
{
    for(int i = 0;i < n;i++)
        taken[i] = false;
}

void read()
{
    int i, j;
    for(i = 0;i < n;i++)
        cin>>pts[i].first>>pts[i].second;
    
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < i;j++)
            a[j][i] = a[i][j] = dist(pts[i], pts[j]);

        a[i][i] = 0;
    }
}

priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > pq;

void solve()
{
    pq.push({0.0, 0});
    double ans = 0;
    pair<double, int> u;
    
    while(!pq.empty())
    {
        u = pq.top();
        pq.pop();

        if(taken[u.second])
            continue;
        taken[u.second] = true;
        ans += u.first;

        for(int v = 0;v < n;v++)
        {
            if(!taken[v])
                pq.push({a[u.second][v], v});
        }
    }

    printf("%0.2lf\n", ans);
}

int main()
{
    int t;
    cin>>t;
    for(int i = 0;i < t;i++)
    {
        if(i)
            cout<<"\n";
        cin>>n;
        reset();
        read();
        solve();
    }
    return 0;
}