#include<iostream>
#include<sstream>
#include<queue>
#include<vector>
#include<cmath>

using namespace std;

const int N = 215;
const double INF = 1e+15, eps = 1e-10;

int n;
vector<vector<pair<double, int> > > a;
pair<int, int> coords[N];
vector<pair<int, int> > elist_subway;
priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > pq;
double dist[N];

string s;
stringstream ss;

void reset()
{
    a.clear();
    elist_subway.clear();

    while(!pq.empty())
        pq.pop();
}

double distance(int i, int j)
{
    double val = (coords[i].first - coords[j].first) * (coords[i].first - coords[j].first);
    val += (coords[i].second - coords[j].second) * (coords[i].second - coords[j].second);
    return sqrt(val);
}

void read()
{
    getline(cin, s);
    ss.clear();
    ss.str(s);
    ss >> coords[0].first >> coords[0].second;
    ss >> coords[1].first >> coords[1].second;
    n = 2;

    while(getline(cin, s))
    {
        if(s == "")
            break;
        
        ss.clear();
        ss.str(s);
        ss >> coords[n].first >> coords[n].second;
        // cout<<coords[n].first <<" "<< coords[n].second<<" | ";
        n ++;
        
        while(!ss.eof())
        {
            ss >> coords[n].first >> coords[n].second;
            // cout<<coords[n].first <<" "<< coords[n].second<<" | ";
            if(coords[n].first == -1 && coords[n].second == -1)
                break;
            
            elist_subway.push_back({n, n - 1});
            n ++;
        }
        // cout<<"\n";
    }

    a.resize(n);
    for(int i = 0;i < n;i++)
        dist[i] = INF;

    double dst;
    for(auto e : elist_subway)
    {
        dst = distance(e.first, e.second) * 0.0015;
        a[e.first].push_back({dst, e.second});
        a[e.second].push_back({dst, e.first});
    }

    int i, j;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            if(i == j)
                continue;
            dst = distance(i, j) * 0.006;
            a[i].push_back({dst, j});
            a[j].push_back({dst, i});
        }
    }
}

void solve()
{
    dist[0] = 0.0;
    pq.push({0.0, 0});
    pair<double, int> u;

    while(!pq.empty())
    {
        u = pq.top();
        // cout<<u.first<<" "<<u.second<<"--\n";
        pq.pop();

        if(u.second == 1)
            break;

        if(abs(dist[u.second] - u.first) > eps)
            continue;
        
        for(auto v : a[u.second])
        {
            // cout<<v.first<<" "<<v.second<<"--||\n";
            if(dist[u.second] + v.first < dist[v.second])
            {
                dist[v.second] = dist[u.second] + v.first;
                pq.push({dist[v.second], v.second});
            }
        }
    }

    cout<<round(dist[1])<<"\n";
}

int main()
{
    int t;
    getline(cin, s);
    ss.clear();
    ss.str(s);
    ss >> t;
    getline(cin, s);

    for(int i = 0;i < t;i++)
    {
        if(i)
            cout<<"\n";
        reset();
        read();
        solve();
    }
}