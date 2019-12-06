#include<iostream>
#include<queue>
#include<algorithm>
#include<map>

using namespace std;

const int N = 10;
map<string, int> dist;
string start, end_string;
queue<string> q;

void reset()
{
    dist.clear();
    while(!q.empty())
        q.pop();
}

void bfs()
{
    if(start == end_string)
    {
        cout<<"0\n";
        return;
    }
    string u, v;
    dist[start] = 0;
    q.push(start);

    int i, j, dval;

    while(!q.empty())
    {
        u = q.front();
        q.pop();
        dval = dist[u];

        for(i = 0;i < N;i++)
        {
            for(j = i + 1;j < N;j++)
            {
                v = u;
                reverse(v.begin() + i, v.begin() + j + 1);
                if(dist.find(v) == dist.end())
                {
                    dist[v] = dval + 1;
                    q.push(v);
                    if(v == end_string)
                    {
                        cout<<dist[v]<<"\n";
                        return;
                    }
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    while(cin>>start>>end_string)
    {
        if(start[0] == '*' && end_string[0] == '*')
            break;
        reset();
        bfs();
    }
}