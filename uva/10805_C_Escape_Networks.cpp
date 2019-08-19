#include<iostream>
#include<vector>
#define MAX 100000000

using namespace std;

int n, m;
int dist[2000][2000];

void reset_dist()
{
    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
            dist[i][j] = MAX;
        dist[i][i] = 0;
    }
}

void read()
{
    int x, y;
    cin>>n>>m;
    n += m;
    reset_dist();

    for(int i = 0;i < m;i++)
    {
        cin>>x>>y;
        dist[x][n - m + i] = dist[n - m + i][x] = 1;
        dist[y][n - m + i] = dist[n - m + i][y] = 1;
    }
}

void solve(int cn)
{
    int i, j, k;

    for(k = 0;k < n;k++)
    {
        for(i = 0;i < n;i++)
        {
            for(j = 0;j < n;j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }

    int solution = MAX;

    for (int i = 0; i < n; i++) {
        int first = 0, second = 0;
        for (int j = 0; j < n - m; j++)
            if (dist[i][j] >= first) {
                second = first;
                first = dist[i][j];
            }
            else if (dist[i][j] > second)
                second = dist[i][j];

        solution = min(solution, first + second); 
    }
    cout << "Case #" << cn<< ":\n";
    cout << solution / 2 <<"\n\n";
}

int main()
{
    int t;
    cin>>t;

    for(int i = 1;i <= t;i++)
    {
        read();
        solve(i);
    }

    return 0;
}