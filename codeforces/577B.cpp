#include<iostream>

using namespace std;

int n, m;
int a[1005];
bool can[1005][1005];

void reset()
{
    int i, j;
    for(i = 0;i <= n;i++)
    {
        for(j = 0;j <= m;j++)
            can[i][j] = false;
    }
}

void read()
{
    cin>>n>>m;
    int x;
    
    for(int i = 0;i < n;i++)
    {
        cin>>x;
        if(n <= m)
        {
            x %= m;
            if(x < 0)
                x += m;
            a[i] = x;
        }
    }
}

bool solve()
{
    if(n > m)
        return true;

    reset();

    int i, r;
    for(i = 0;i <= n - 2;i++)
    {
        can[i][a[i] % m] = true;                         // We can form a[i] % m using just a[i]
        for(r = 0;r < m;r++)
        {
            can[i + 1][(r + a[i + 1]) % m] |= can[i][r]; // Pick a[i + 1]
            can[i + 1][r] |= can[i][r];                  // Do not pick a[i + 1]
        }
    }
    can[n - 1][a[n - 1] % m] = true;

    for(i = 0;i < m;i++)
    {
        if(can[i][0])
            return true;
    }

    return false;
}

int main()
{
    read();
    if(solve())
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}