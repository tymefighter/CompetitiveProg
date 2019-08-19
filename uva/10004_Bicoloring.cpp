#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
vector<vector<int> > adj;
vector<int> color;

void clearAll()
{
    adj.clear();
    color.clear();
}

void read()
{
    int a, b;
    adj.resize(n);
    color.assign(n, -1);
    cin>>m;

    for(int i = 0;i < m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

bool check()
{
    int u;
    queue<int> q;

    q.push(0);
    color[0] = 0;

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(int v : adj[u])
        {
            if(color[v] == -1)
            {
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if(color[v] == color[u])
                return false;
        }
    }

    return true;
}


int main()
{
    int a, b;
    while(cin>>n)
    {
        if(!n)
            break;
        clearAll();
        read();
        if(check())
            cout<<"BICOLORABLE.\n";
        else
            cout<<"NOT BICOLORABLE.\n";   
        
    }

    return 0;
}