#include<iostream>

using namespace std;

const int MAX = 1005;

int k, t;
bool reach[MAX][MAX];

void reset()
{
    int i, j;
    for(i = 0;i < k;i++)
    {
        for(j = 0;j < k;j++)
            reach[i][j] = false;
        reach[i][i] = true;
    }
}

void read_solve()
{
    cin>>k>>t;
    reset();

    int u, v;
    for(int i = 0;i < t;i++)
    {
        cin>>u>>v;
        u --, v --;

        if(reach[v][u])
        {
            cout<<u + 1<<" "<<v + 1<<"\n";
            continue;
        }

        reach[u][v] = true;

        for(int node = 0;node < k;node ++)
        {
            if(reach[node][u])      // Error.....
                reach[node][v] = true;

            if(reach[v][node])      // Error.....
                reach[u][node] = true;
        }
    }

    cout<<"0 0\n";
}

int main()
{
    read_solve();
    return 0;
}