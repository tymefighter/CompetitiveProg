#include<iostream>
#include<bitset>
#include<queue>
#include<string>
#include<sstream>
#include<cstdio>
#define INF 100000000

using namespace std;

/*
    source: 0
    apps: 1 - 26
    computers: 27 - 36
    sink: 37
*/

int res[38][38];
int p[38];
bitset<38> vis;
queue<int> q;
string s;
stringstream ss;
int f;

void reset()
{
    int i, j;
    for(i = 0;i < 38;i++)
    {
        p[i] = -1;
        for(j = 0;j < 38;j++)
            res[i][j] = 0;
    }

    ss.clear();
    ss.str("");
}

void read_line()
{
    ss.clear();
    ss.str(s);
    ss >> s;
    int app = s[0] - 'A' + 1, w = s[1] - '0', comp;
    res[0][app] = w; // source to app

    ss >> s;

    for(char x : s)
    {
        if(x == ';')
            break;
        comp = 27 + x - '0';
        res[app][comp] = INF; // app to computer
    }
}

void read()
{
    read_line();

    while(getline(cin, s))
    {
        if(s == "")
            break;

        read_line();
    }

    for(int comp = 27; comp <= 36; comp++)
        res[comp][37] = 1; // computer to sink
}

void augment(int v, int minEdge)
{
    if(v == 0)
        f = minEdge;
    else if(p[v] != -1)
    {
        augment(p[v], min(res[p[v]][v], minEdge));
        res[p[v]][v] -= f; // forward edge
        res[v][p[v]] += f; // reverse edge
    }
}

void EdmondsKarp()
{
    int mf = 0;
    int u, v;

    while(true)
    {
        while (!q.empty())
            q.pop();

        f = 0;
        vis.reset(); // set all to false
        vis[0] = true; 
        q.push(0);
        
        while(!q.empty())
        {
            u = q.front(), q.pop();
            if(u == 37)
                break;

            for(v = 0;v < 38;v++)
            {
                if(res[u][v] > 0 && !vis[v])
                {
                    vis[v] = true;
                    p[v] = u;
                    q.push(v);
                }
            }
        }

        augment(37, INF);
        if(f == 0)
            break;
        mf += f;
    }

    if(!mf)
    {
        cout<<"!\n";
        return;
    }

    for(v = 1;v <= 26;v++)
    {
        if(res[0][v] != 0)
        {
            cout<<"!\n";
            return;
        }
    }

    for(u = 27;u <= 36;u++)
    {
        for(v = 1;v <= 26;v++)
        {
            if(res[u][v] == 1)
            {
                cout<<(char)(v - 1 + 'A');
                break;
            }
        }
        if(v == 27)
            cout<<"_";
    }
    cout<<"\n";

}

int main()
{

    while(getline(cin, s))
    {
        if(s == "")
            break;
        reset();
        read();
        EdmondsKarp();
    }

    return 0;
}