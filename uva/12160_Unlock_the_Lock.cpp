#include<iostream>
#include<queue>
#include<cstdio>

using namespace std;

int dist[10000];
int a[11];
int s, e, n;
queue<int> q;

void read()
{
    int i;
    for(i = 0;i < n;i++)
        scanf("%04d", &a[i]);
    
    for(i = 0;i < 10000;i++)
        dist[i] = -1;
}

int bfs()
{
    dist[s] = 0;
    q.push(s);
    int i, x, val, ans = -1;

    if(s == e)
    {
        q.pop();
        return 0;
    }

    while(!q.empty())
    {
        x = q.front();
        q.pop();
        for(i = 0;i < n;i++)
        {
            val = (x + a[i]) % 10000;
            if(dist[val] == -1)
            {
                dist[val] = dist[x] + 1;
                if(val == e)
                {
                    ans =  dist[val];
                    break;
                }
                q.push(val);
            }
        }
    }

    while(!q.empty())
        q.pop();


    return ans;
}

int main()
{
    int ans, case_no = 1;
    while(scanf("%04d %04d %d", &s, &e, &n) == 3)
    {
        if(!(s|e|n))
            break;
        read();
        ans = bfs();

        if(ans == -1)
            printf("Case %d: Permanently Locked\n", case_no);
        else
            printf("Case %d: %d\n", case_no, ans);
        case_no++;
    }
    return 0;
}
