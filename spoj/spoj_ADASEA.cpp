#include<iostream>
#include<vector>

using namespace std;

const int MAX_SIZE = 1005;

int n, m;
char a[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];


void read()
{
    cin>>n>>m;
    int i, j;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            cin>>a[i][j];
            visited[i][j] = false;
        }
    }
}

int ar[] = {-1, 1, 0, 0};
int ac[] = {0, 0, -1, 1};

int dfs(int r, int c)
{
    visited[r][c] = true;
    int sum_val = 1, rd, cd;
    for(int i = 0;i < 4;i++)
    {
        rd = r + ar[i];
        cd = c + ac[i];
        if(rd < 0 || rd >= n || cd < 0 || cd >= m
            || a[rd][cd] == '~' || visited[rd][cd])
            continue;
        sum_val += dfs(rd, cd);
    }

    return sum_val;
}

long long gcd(long long a, long long b)
{
    if(a == 0)
        return b;
    
    return gcd(b % a, a);
}

void solve()
{
    int i, j;
    long long ans = 0, val;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            if(!visited[i][j] && a[i][j] == '#')
            {
                val = dfs(i, j);
                ans += val * val;
            }
        }
    }

    long long gcd_val = gcd(ans, n * m);

    if(ans % (n * m) == 0)
        printf("%lld\n", ans / (n * m));
    else
        printf("%lld / %lld\n", ans / gcd_val, (n * m) / gcd_val);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        read();
        solve();
    }
    return 0;
}