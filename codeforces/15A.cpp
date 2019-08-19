#include<iostream>
#include<algorithm>

using namespace std;

int n;
float t;
float s[1005], e[1005];

void read()
{
    cin>>n>>t;

    float c, d;
    for(int i = 0;i < n;i++)
    {
        cin>>c>>d;
        s[i] = c - (d / 2);
        e[i] = c + (d / 2);
    }

    sort(s, s + n);
    sort(e, e + n);
}

void solve()
{
    int ans = 2;
    int i;
    float prev, end;

    for(i = 1;i <= n - 1;i++)
    {
        prev = e[i - 1], end = s[i];

        if((end - prev) == t)
            ans ++;
        else if((end - prev) > t)
            ans += 2;
    }

    cout<<ans<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}