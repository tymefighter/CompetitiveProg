#include<iostream>

using namespace std;

int n, m, q;
bool row[100005], col[100005];

void reset()
{
    for(int i = 0;i < n;i++)
        row[i] = false;

    for(int i = 0;i < m;i++)
        col[i] = false;
}

void solve()
{
    int r, c;
    while(q--)
    {
        cin>>r>>c;
        r --, c--;
        row[r] = !row[r];
        col[c] = !col[c];
    }

    long long col_odd = 0, ans = 0;

    for(c = 0;c < m;c++)
        col_odd += (col[c] ? 1 : 0);
    
    for(r = 0;r < n;r++)
    {
        if(!row[r])
            ans += col_odd;
        else
            ans += (m - col_odd);
    }

    cout<<ans<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>q;
        reset();
        solve();
    }
    return 0;
}