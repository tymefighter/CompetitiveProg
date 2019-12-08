#include<iostream>
#include<vector>
#include<sstream>
#include<queue>

using namespace std;

int n;
vector<vector<int> > a;
stringstream ss;
string line;
vector<int> dist, pred;
queue<int> q;

void reset()
{
    a.clear();
    a.resize(n);
}

void read()
{
    int v;
    char ignore_char;
    for(int i = 0;i < n;i++)
    {
        getline(cin, line);
        ss.clear();
        ss.str(line);

        ss >> v;
        ss >> ignore_char;

        while(true)
        {
            if(ss.eof())
                break;
            ss >> v;
            a[i].push_back(v - 1);
            ss >> ignore_char;
        }
    }
}

void resetBFS()
{
    dist.clear();
    dist.assign(n, -1);
    pred.clear();
    pred.assign(n, -1);
    while(!q.empty())
        q.pop();
}

void bfs(int u, int dest)
{
    dist[u] = 0;
    q.push(u);

    while(!q.empty())
    {
        u = q.front(), q.pop();

        for(int v : a[u])
        {
            if(dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                pred[v] = u;
                q.push(v);
            }
        }
    }
}

void printPath(int u)
{
    if(u == -1)
        return;
    
    printPath(pred[u]);
    if(pred[u] != -1)
        cout<<" ";
    cout<<u + 1;
}

void solve()
{
    int q, source, dest;
    getline(cin, line);
    ss.clear();
    ss.str(line);
    ss >> q;

    while(q--)
    {
        getline(cin, line);
        ss.clear();
        ss.str(line);
        resetBFS();
        ss >> source >> dest;
        source --, dest--;

        bfs(source, dest);
        if(dist[dest] == -1)
            printf("connection impossible");
        else
            printPath(dest);
        cout<<"\n";
    }
}

int main()
{
    while(getline(cin, line))
    {
        ss.clear();
        ss.str(line);
        ss >> n;
        reset();
        read();
        printf("-----\n");
        solve();
    }
}