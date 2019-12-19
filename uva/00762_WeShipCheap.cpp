#include<iostream>
#include<queue>
#include<vector>
#include<bitset>

using namespace std;

const int N = 676;

vector<vector<int> > a;
int p[N], m;
queue<int> q;
bitset<N> vis;

void reset()
{
    a.clear();
    a.resize(N);
    vis.reset();

    while(!q.empty())
        q.pop();
}

void read()
{
    char c;
    int u, v;
    for(int i = 0;i < m;i++)
    {
        cin>>c;
        u = 26 * (c - 'A');
        cin>>c;
        u += c - 'A';

        cin>>c;
        v = 26 * (c - 'A');
        cin>>c;
        v += c - 'A';

        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void getName(int i)
{
    cout<<(char)('A' + (char)(i / 26))<<(char)('A' + (char)(i % 26));
}

void printPath(int s, int v)
{
    if(p[v] == s)
    {
        getName(s);
        cout<<" ";
        getName(v);
        return;
    }

    printPath(s, p[v]);
    cout<<"\n";
    getName(p[v]);
    cout<<" ";
    getName(v);
}

void solve()
{
    int s, t;
    char c;
    
    cin>>c;
    s = 26 * (c - 'A');
    cin>>c;
    s += c - 'A';

    cin>>c;
    t = 26 * (c - 'A');
    cin>>c;
    t += c - 'A';

    vis[s] = true;
    q.push(s);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(u == t)
            break;

        for(int v : a[u])
        {
            if(!vis[v])
            {
                vis[v] = true;
                p[v] = u;
                q.push(v);
            }
        }
    }

    if(!vis[t])
    {
        cout<<"No route\n";
        return;
    }

    printPath(s, t);
    cout<<"\n";
}

int main()
{
    int ct = 0;
    while(cin>>m)
    {
        if(ct)
            cout<<"\n";
        reset();
        read();
        solve();
        ct ++;
    }
    return 0;
}