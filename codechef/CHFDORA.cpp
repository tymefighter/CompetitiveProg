#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<vector<int> > a;

void reset()
{
    a.clear();
    a.assign(n, vector<int>(m));
}

void read()
{
    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
            cin>>a[i][j];
    }
}

void solve()
{
    int i, j, k;
    long long ans = 0;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            long long max_len = 0;
            for(k = 0;k < min(n - i, m - j);k++)
            {
                int i_right = i + k, i_left = i - k;
                int j_down = j + k, j_up = j - k;

                if(i_left < 0 || j_up < 0)
                    break;
                
                if(a[i_right][j] != a[i_left][j]
                    || a[i][j_down] != a[i][j_up])
                    break;
                max_len ++;
            }
            ans += max_len;
        }
    }

    cout<<ans<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        reset();
        read();
        solve();
    }
    return 0;
}