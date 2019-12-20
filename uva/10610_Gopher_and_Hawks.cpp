#include<iostream>
#include<queue>
#include<sstream>
#include<cmath>

using namespace std;

const int N = 1005;
stringstream ss;
string st;

int v, m, n;
pair<double, double> coord[N];
int s, t;

void read()
{
    getline(cin, st);
    ss.clear();
    ss.str(st);
    ss >> coord[0].first >> coord[0].second;
    getline(cin, st);
    ss.clear();
    ss.str(st);
    ss >> coord[1].first >> coord[1].second;

    s = 0, t = 1;

    n = 2;
    while(getline(cin, st))
    {
        if(st == "")
            break;
        
        ss.clear();
        ss.str(st);
        ss >> coord[n].first >> coord[n].second;
        n ++;
    }
}

queue<int> q;
int dist[N];

void resetBFS()
{
    while(!q.empty())
        q.pop();
    
    for(int i = 0;i < n;i++)
        dist[i] = -1;
}

double sq_norm(int i, int j)
{
    double val = (coord[i].first - coord[j].first) * (coord[i].first - coord[j].first);
    val += (coord[i].second - coord[j].second) * (coord[i].second - coord[j].second);
    return sqrt(val);
}

bool less_eq(const double &a, const double &b)
{
    static double eps = 1e-7;
    if(a <= b + eps)
        return true;
    return false;
}

void solve()
{
    resetBFS();
    dist[s] = 0;
    q.push(s);

    v *= 60;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(u == t)
            break;

        for(int i = 0;i < n;i++)
        {
            if(dist[i] == -1 && less_eq(sq_norm(u, i) / (double)v, (double)m))
            {
                dist[i] = dist[u] + 1;
                q.push(i);
            }
        }
    }

    if(dist[t] == -1)
        cout<<"No.\n";
    else
        printf("Yes, visiting %d other holes.\n", dist[t] - 1);
}

int main()
{
    while(getline(cin, st))
    {
        ss.clear();
        ss.str(st);
        ss >> v >> m;
        if(!(v | m))
            break;
        read();
        solve();
    }
    return 0;
}