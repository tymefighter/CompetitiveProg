#include<iostream>
#include<set>

using namespace std;

const int INF = 100000000;
int p, n;
int a[105];

void read()
{
    cin>>p>>n;

    int i, j, x;
    char c;

    for(i = 0;i < n;i++)
    {
        x = 0;
        for(j = 0;j < p;j++)
        {
            cin>>c;
            if(c == '1')
                x |= (1 << j);
        }
        a[i] = x;
    }
}

bool check(int i)
{
    set<int> s;

    for(int j = 0;j < n;j++)
        s.insert(a[j] & i);

    return s.size() == n;
}

int numSet(int i)
{
    int val = 0;
    for(int j = 1;j <= i;j = (j << 1))
        val += ((i & j) != 0 ? 1 : 0);
    
    return val;
}

void solve()
{
    int ans = INF;
    for(int i = 0;i < (1 << p);i++)
    {
        if(check(i))
            ans = min(ans, numSet(i));
    }

    cout<<ans<<"\n";
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