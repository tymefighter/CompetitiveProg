#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<cmath>
#include<queue>

using namespace std;

int n, state;
float r, road, rail;
float a[1002][1002];
bool taken[1002];
pair<double, double> coords[1002];
priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > pq;

double dist(pair<double, double> a, pair<double, double> b)
{
    double d;

    d = (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    d = sqrt(d);

    return d;
}


void read()
{
    cin>>n>>r;
    int i, j;
    double d;

    for(i = 0;i < n;i++)
    {
        cin>>coords[i].first>>coords[i].second;
        taken[i] = false;
        for(j = 0;j < i;j++)
        {
            d = dist(coords[i], coords[j]);
            a[i][j] = a[j][i] = d;
        }
    }
}

void prim()
{
    pq.push({0, 0});
    int v;
    pair<float, int> u;
    state = 1;
    road = rail = 0.;

    while(! pq.empty())
    {
        u = pq.top();
        pq.pop();

        if(taken[u.second])
            continue;
        
        taken[u.second] = true;
        if(u.first <= r)
            road += u.first;
        else
        {
            rail += u.first;
            state++;
        }

        for(v = 0;v < n;v++)
        {
            if(taken[v])
                continue;
            pq.push({a[u.second][v], v});
        }
    }
}

int round_val(double x)
{
    int val;
    x += 0.5;
    if(floor(x) == ceil(x))
    {
        val = (int)x % 2;
        if(val % 2 != 0)
        {
            x -= 1.;
        }
    }
    return (int)x;
}


int main()
{
    int i, t;
    cin>>t;

    for(i = 1;i <= t;i++)
    {
        read();
        prim();
        printf("Case #%d: %d %d %d\n", i, state, round_val(road), round_val(rail));
        //printf("Case #%d: %d %0.4f %0.4f\n", i, state, road, rail);
    }
    return 0;
}