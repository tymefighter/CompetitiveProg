#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int a[101][101];
bool visited[101][101];

int R, C, M, N, W;
int even, odd;

void read()
{
    cin>>R>>C>>M>>N;
    cin>>W;
    int r, c;

    even = odd = 0;
    memset(a, 1, sizeof(a));
    memset(visited, false, sizeof(visited));

    for(int i = 0;i < W;i++)
    {
        cin>>r>>c;
        a[r][c] = 0;
    }
}


int dfs(int r, int c)
{
    if(r >= R || r < 0 || c >= C || c < 0 || a[r][c] == 0)
        return 0;
    else if(visited[r][c])
        return 1;
    
    visited[r][c] = true;
    int ct = 0;


    if(M != 0 && N != 0 && M != N)
    {
        ct += dfs(r+M, c+N);
        ct += dfs(r+M, c-N);
        ct += dfs(r-M, c+N);
        ct += dfs(r-M, c-N);
        ct += dfs(r+N, c+M);
        ct += dfs(r+N, c-M);
        ct += dfs(r-N, c+M);
        ct += dfs(r-N, c-M);
    }
    else if(M == 0)
    {
        ct += dfs(r, c+N);
        ct += dfs(r, c-N);
        ct += dfs(r+N, c);
        ct += dfs(r-N, c);
    }
    else if(N == 0)
    {
        ct += dfs(r+M, c);
        ct += dfs(r-M, c);
        ct += dfs(r, c+M);
        ct += dfs(r, c-M);
    }
    else
    {
        ct += dfs(r+M, c+M);
        ct += dfs(r+M, c-M);
        ct += dfs(r-M, c+M);
        ct += dfs(r-M, c-M);
    }

    if(ct % 2)
        odd++;
    else
        even++;

    return 1;
}

int main()
{
    int t;
    cin>>t;

    for(int i = 1;i <= t;i++)
    {
        read();
        dfs(0, 0);
        printf("Case %d: %d %d\n", i, even, odd);
    }

    return 0;
}