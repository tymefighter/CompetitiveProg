#include<iostream>
#include<queue>

using namespace std;

int n, m, k, start;
pair<int, int> light[10005];
int dist[10005];
deque<int> deq;

void reset()
{
    while(!deq.empty())
        deq.pop_back();
}

void read()
{
    cin>>n>>m>>k;
    for(int i = 0;i < k;i++)
    {
        cin>>light[i].first>>light[i].second;
        light[i].first --, light[i].second --;
        if(!(light[i].first | light[i].second))
            start = i;
        dist[i] = -1;
    }
}

bool isAdj(int i, int j)
{
    if(abs(light[i].first - light[j].first)
        + abs(light[i].second - light[j].second) == 1)
        return true;
    else
        return false;
}

void solve()
{
    dist[start] = 0;
    deq.push_back(start);

    int i, j, ans = -1;

    while(!deq.empty())
    {
        i = deq.front();
        deq.pop_front();

        if(light[i].first == n - 1
            && light[i].second == m - 1)
        {
            ans = dist[i];
            break;
        }

        if(ans == -1 && (abs(light[i].first - (n - 1)) <= 1 || abs(light[i].second - (m - 1)) <= 1))
            ans = dist[i] + 1;

        for(int j = 0;j < k;j++)
        {
            if(dist[j] == -1 && !isAdj(i, j))
            {
                if(abs(light[j].first - light[i].first) <= 2 
                    || abs(light[j].second - light[i].second) <= 2)
                {
                    dist[j] = dist[i] + 1;
                    deq.push_back(j);
                }
            }

            if(isAdj(i, j) && 
                (dist[j] == -1 || dist[i] < dist[j]))
            {
                dist[j] = dist[i];
                deq.push_front(j);
            }
        }
    }

    cout<<ans<<"\n";
}

int main()
{
    reset();
    read();
    solve();
    return 0;
}