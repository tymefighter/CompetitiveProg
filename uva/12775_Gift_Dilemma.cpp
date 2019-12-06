#include<iostream>
#include<climits>
#include<cmath>

using namespace std;

int extended_euclid(int a, int b, long long &x, long long &y)
{
    if(a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }

    int g;
    long long x1, y1;
    g = extended_euclid(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return g;
}

int a, b, c, p, g;

long long get_num_sol(int r, long long x, long long y)
{
    long long mink, maxk;

    if(r % g)
        return 0;

    x *= r / g;
    y *= r / g;

    mink = ceil(-x / (double)b);
    maxk = floor(y / (double)a);

    if(maxk >= mink)
        return maxk - mink + 1;
    else
        return 0;
}

void solve(int cno)
{
    long long ans = 0, x, y;
    g = extended_euclid(a, b, x, y);
    if(g < 0)
    {
        x = -x;
        y = -y;
        g = -g;
    }
    a /= g;
    b /= g;

    for(int z = 0;z <= p / c;z++)
    {
        ans += get_num_sol(p - c * z, x, y);
    }

    printf("Case %d: %lld\n", cno, ans);
}

int main()
{
    int t;
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        cin>>a>>b>>c>>p;
        solve(i);
    }
    return 0;
}