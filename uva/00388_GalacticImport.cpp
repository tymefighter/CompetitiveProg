#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

const int N = 27;
const double eps = 1e-7;

int dist[N];
double value[N];
vector<vector<int> > a;
queue<int> q;

void reset()
{
    a.clear();
    a.resize(N);

    for(int i = 0;i < N;i++)
        dist[i] = -1;
}

void read(int n)
{
    char c;
    double val;
    string s;
    for(int i = 0;i < n;i++)
    {
        cin>>c>>val>>s;
        value[c - 'A'] = val;
        for(char x : s)
        {
            if(x == '*')
            {
                a[26].push_back(c - 'A');
                a[c - 'A'].push_back(26);
            }
            else
                a[c - 'A'].push_back(x - 'A');
        }
    }
}

void solve()
{
    q.push(26);
    dist[26] = 0;
    int u;

    while(!q.empty())
    {
        u = q.front(), q.pop();
        for(int v : a[u])
        {
            if(dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    char ans;
    double ans_val = -1.0, val;

    for(u = 0;u < N;u++)
    {
        if(dist[u] <= 0)
            continue;

        val = value[u];
        for(int i = 0;i < dist[u];i++)
            val *= 0.95;

        if(val > ans_val + eps)
        {
            ans = (char)(u + 'A');
            ans_val = val;
        }
    }

    printf("Import from %c\n", ans);
}

int main()
{
    int n;
    while(cin>>n)
    {
        reset();
        read(n);
        solve();
    }
    return 0;
}