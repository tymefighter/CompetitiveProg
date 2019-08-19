#include<iostream>

using namespace std;

int n;
int b[100005], a[100005];

void read()
{
    cin>>n;
    for(int i = 0;i < n;i++)
        cin>>b[i];
}

int solve2()
{
    int d = a[1] - a[0];
    int val = 0;

    for(int i = 2;i < n;i++)
    {
        if(a[i] - a[i - 1] == d)
            continue;
        if(a[i] - a[i - 1] == d + 1)
        {
            val++;
            a[i]--;
        }
        else if(a[i] - a[i - 1] == d - 1)
        {
            val++;
            a[i]++;
        }
        else
            return -1;
    }

    return val;
}

void solve()
{
    int i, j, k;
    int ans = -1, val;
    for(i = -1;i <= 1;i++)
    {
        for(j = -1;j <= 1;j++)
        {
            a[0] = b[0] + i;
            a[1] = b[1] + j;

            for(k = 2;k < n;k++)
                a[k] = b[k];

            val = solve2();
            if(val != -1)
            {
                val += (i == 0 ? 0 : 1);
                val += (j == 0 ? 0 : 1);
                if(ans == -1 || val < ans)
                    ans = val;
            }
        }
    }

    cout<<ans<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}
