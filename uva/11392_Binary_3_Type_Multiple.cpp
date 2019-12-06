#include<iostream>
#include<queue>

using namespace std;

int k;
pair<int, int> dist[1000005][2];
queue<pair<int, int> > q;

void reset()
{
    int i, j;

    for(i = 0;i < k;i++)
    {
        for(j = 0;j < 2;j++)
            dist[i][j] = {-1, -1};
    }

    while(!q.empty())
        q.pop();
}

int bfs()
{
    pair<int, int> u, v;
    v = {3 % k, 1};         // 1: means 3, 0: means 0       
    dist[v.first][1] = {0, 1};
    if(v.first == 0)
        return 1;
    q.push({3 % k, 1});  

    

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        v.first = (10 * u.first) % k;
        v.second = 0;
        if(dist[v.first][v.second].first == -1)
        {
            dist[v.first][v.second] = dist[u.first][u.second];
            dist[v.first][v.second].first += 1;

            if(v.first == 0)
                return v.second;

            q.push(v);
        }

        if(u.second == 1)
        {
            v.first = (10 * u.first + 3) % k;
            v.second = 1;

            if(dist[v.first][v.second].first == -1)
            {
                dist[v.first][v.second] = dist[u.first][u.second];
                dist[v.first][v.second].second += 1;

                if(v.first == 0)
                    return v.second;

                q.push(v);
            }
        }
    }

    return -1;
}

int main()
{
    int final_dig, ans;
    pair<int, int> ans_digs;
    while(cin>>k)
    {
        reset();
        final_dig = bfs();
        ans_digs = dist[0][final_dig];
        ans = ans_digs.first + ans_digs.second;
        cout<<ans<<" "<<ans_digs.second<<" "<<ans_digs.first<<"\n";
    }
    return 0;
}