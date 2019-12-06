#include<iostream>
#include<bitset>
#include<queue>

using namespace std;

int n;
bitset<10> dig;
bool vis[10005];
pair<int, int> pre[10005];
queue<int> q;

void reset()
{
    for(int i = 0;i < n;i++)
    {
        vis[i] = false;
        pre[i] = {-1, -1};
    }

    while(!q.empty())
        q.pop();
}

void read()
{
    int m, x;
    cin>>m;

    dig.set();
    for(int i = 0;i < m;i++)
    {
        cin>>x;
        dig[x] = false;
    }
}

void printPath(int u)
{
    if(u == -1)
    {
        return;
    }
    printPath(pre[u].first);
    cout<<pre[u].second;
}

void bfs()
{
    int u, v;
    for(int i = 0;i < 10;i++)
    {
        if(!dig[i] || !i)
            continue;

        v = i % n;
        vis[v] = true;
        pre[v] = {-1, i};
        if(v == 0)
        {
            printPath(0);
            cout<<"\n";
            return;
        }
        q.push(v);
    }
    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(int i = 0;i < 10;i++)
        {
            if(!dig[i])
                continue;

            v = (10 * u + i) % n;
            if(vis[v])
                continue;

            vis[v] = true;
            pre[v] = {u, i};

            if(v == 0)
            {
                printPath(0);
                cout<<"\n";
                return;
            }
            q.push(v);
        }
    }

    cout<<"-1\n";
    return;
}

int main()
{
    int cno = 1;
    while(cin>>n)
    {
        reset();
        read();
        printf("Case %d: ", cno);
        bfs();
        cno ++;
    }
    return 0;
}